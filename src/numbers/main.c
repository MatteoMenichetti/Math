#include "../../lib/common.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("main: number of elements < 2");
        return EXIT_FAILURE;
    }
    if (*argv[1] < 2) {
        printf("main: prime limit number must be higher than 2");
        return EXIT_FAILURE;
    }

    int log_pid = fork();
    if (log_pid == 0) {
        if (execl("./log", "log", NULL) == -1) {
            perror("main: error on log fork\n");
            exit(EXIT_FAILURE);
        }
    }

    int finder_pid = fork();
    if (finder_pid == 0) {
        if (execl("./finder", "finder", NULL) == -1) {
            perror("main: error on finder fork\n");
            exit(EXIT_FAILURE);
        }
    }

    int server_pid;
    if ((server_pid = fork()) == 0) {
        char *cFinderPid = (char *) malloc(sizeof(int));
        sprintf(cFinderPid, "%d", finder_pid);
        if (execl("./server", "server", cFinderPid, argv[1], NULL) == -1) {
            perror("main: error on server fork");
            kill(finder_pid, SIGKILL);
            kill(log_pid, SIGKILL);
            exit(EXIT_FAILURE);
        }
    }

    waitpid(server_pid, NULL, 0);

    if(kill(log_pid, SIGTERM)==-1){
        perror("main: kill log");
    }

    return EXIT_SUCCESS;
}