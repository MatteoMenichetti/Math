#include "../../lib/log.h"

int main(int argc, char **argv) {

    signal(SIGTERM, sigterm_handler);

    open_log();

    int fd_pipe = open_pipe();

    read_log_pipe(fd_pipe);

    return EXIT_SUCCESS;
}
