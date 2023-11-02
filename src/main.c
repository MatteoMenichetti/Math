#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    if (argc<2){
        printf("main: numero di argomenti insufficienti");
        return -1;
    }
    if (*argv[1]<2)
        perror("main: input minore di 2");
    int finderPid = fork();
    if(finderPid==0){
        if(execl("./finder", "finder", NULL)==-1) {
            printf("main: errore fork finder %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }else{
        char * cFinderPid= malloc(sizeof(int));
        sprintf(cFinderPid, "%d", finderPid);
        if(execl("./server", "server", cFinderPid, argv[1], NULL)==-1) {
            printf("main: errore fork server %d\n", errno);
            kill(finderPid, SIGKILL);
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}