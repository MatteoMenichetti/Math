#include "../../lib/log.h"

int fd_log;


void sigterm_handler(int sig) {
    close(fd_log);

    exit(EXIT_SUCCESS);
}

ssize_t write_on_log(char *msg, int size) {
    ssize_t c_write = 0;
    if ((c_write = write(fd_log, msg, size)) == -1)
        perror("log: write on log");

    return c_write;
}

void open_log() {
    fd_log = open(LOGPATH, O_CREAT | O_WRONLY | O_TRUNC, S_IREAD | S_IWUSR | S_IROTH | S_IRGRP);

    if (fd_log == -1) {
        perror("log: open");
        exit(EXIT_FAILURE);
    }

    write_on_log((char *) "log: start\n", sizeof("log: start"));
}