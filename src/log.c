#include "../lib/log.h"

ssize_t write_on_log(int fd, char *msg, int size) {
    ssize_t c_write = 0;
    if ((c_write = write(fd, msg, size)) == -1)
        perror("log: write on log");

    return c_write;
}

int open_log() {
    int fd = open(LOGPATH, O_CREAT | O_WRONLY | O_TRUNC, S_IREAD + S_IWUSR + S_IROTH + S_IRGRP);

    if (fd == -1) {
        perror("log: open");
        exit(EXIT_FAILURE);
    }

    write_on_log(fd, "log: start\n", sizeof("log: start\n"));

    return fd;
}

int main(int argc, char **argv) {
    int fd = open_log();

    return EXIT_SUCCESS;
}