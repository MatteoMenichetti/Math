#include "../lib/common.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("main: number of elements < 2");
        return EXIT_FAILURE;
    }
    if (*argv[1] < 2) {
        printf("main: prime limit number must be higher than 2");
        return EXIT_FAILURE;
    }
    int finderPid = fork();
    if (finderPid == 0) {
        if (execl("./finder", "finder", NULL) == -1) {
            printf("main: error on finder fork %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }
    if (fork() == 0) {
        if (execl("./log", "log", NULL) == -1) {
            printf("main: error on log fork (errno = %d)\n", errno);
            exit(EXIT_FAILURE);
        }
    }
    char *cFinderPid = (char *) malloc(sizeof(int));
    sprintf(cFinderPid, "%d", finderPid);
    if (execl("./server", "server", cFinderPid, argv[1], NULL) == -1) {
        printf("main: error on server fork (errno = %d)\n", errno);
        kill(finderPid, SIGKILL);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}