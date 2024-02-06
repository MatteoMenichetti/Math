#include "../lib/log.h"

#define MSGSIZE 100

void read_log(int fd) {
    char *msg = (char *) calloc(MSGSIZE, sizeof(char)), *head = msg;

    while (1) {
        do {
            if (read(fd, msg++, sizeof(char)) == 0)sleep(1);
        }
        while (strcmp(msg, "\n") == 0);

        write_on_log(head, strlen(head) * sizeof(char));
    }

}

int main(int argc, char **argv) {

    open_log();

    int fd_pipe = open_pipe();

    read_log(fd_pipe);

    return EXIT_SUCCESS;
}
