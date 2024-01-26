#include "../lib/log.h"

int open_log() {
    int fd = open(LOGPATH, O_CREAT | O_WRONLY | O_TRUNC, S_IREAD + S_IWUSR + S_IROTH + S_IRGRP);

    if (fd == -1) {
        perror("log: open");
        exit(EXIT_FAILURE);
    }

    if (write(fd, "log: start\n", sizeof("log: start\n")) < 0) {
        perror("log: write on general.log");
        exit(EXIT_FAILURE);
    }

    return fd;
}

int main(int argc, char **argv) {
    int fd = open_log();

    return EXIT_SUCCESS;
}