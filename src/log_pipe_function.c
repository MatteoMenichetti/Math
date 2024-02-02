#include "../lib/log.h"

int open_pipe() {
    unlink(LOGPIPE);
    // S_IREAD = S_IRUSR & S_IWRITE = S_IWUSR;
    if (mknod(LOGPIPE, S_IFIFO | S_IREAD | S_IWRITE, 0) == -1) {
        perror("log: mknod");
    }

    write_on_log((char*)"log: mknod\n", sizeof("log: mknod"));

    int fd = open(LOGPIPE, O_RDONLY);
    if (fd == -1) {
        char failure_msg[] = "log: open %s failure\n", *msg = (char *) calloc(sizeof(failure_msg) + sizeof(LOGPIPE),
                                                                              sizeof(char));
        int size = sprintf(msg, failure_msg, LOGPIPE);

        perror(msg);
    }

    write_on_log((char*)"log: pipe open\n", sizeof("log: pipe open"));

    return fd;
}