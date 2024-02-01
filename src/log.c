#include "../lib/log.h"

int main(int argc, char **argv) {
    open_log();

    int fd_pipe = open_pipe();

    return EXIT_SUCCESS;
}
