#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char ** argv) {
    if (argc<2){
        printf("Numero di argomenti insufficienti");
        return -1;
    }
    int finderPid = fork();
    if(finderPid==0)
        execl("./finder", "finder");
    execl("./server", "server");
    return 0;
}
