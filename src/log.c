#include "../lib/log.h"

int fd_log;

ssize_t write_on_log(char *msg, int size) {
    ssize_t c_write = 0;
    if ((c_write = write(fd_log, msg, size)) == -1)
        perror("log: write on log");

    return c_write;
}

void open_log() {
    fd_log = open(LOGPATH, O_CREAT | O_WRONLY | O_TRUNC, S_IREAD + S_IWUSR + S_IROTH + S_IRGRP);

    if (fd_log == -1) {
        perror("log: open");
        exit(EXIT_FAILURE);
    }

    write_on_log("log: start\n", sizeof("log: start\n"));
}

int open_pipe() {
    unlink(LOGPIPE);
    mknod(LOGPIPE, S_IFIFO + S_IREAD + S_IWGRP, 0);

    int fd = open(LOGPIPE, O_RDONLY);
    if (fd == -1) {
        char *msg = (char *) calloc(sizeof("log: open %s failure") + sizeof(LOGPIPE), sizeof(char));
        int size = sprintf(msg, "log: open %s failure", LOGPIPE);

        write_on_log(msg, size);

        perror(msg);
    }
    return fd;
}

int main(int argc, char **argv) {
    open_log();
    int fd_pipe = open_pipe();

    return EXIT_SUCCESS;
}