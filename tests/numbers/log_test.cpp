#include <gtest/gtest.h>

extern "C" {
#include "../../lib/log.h"
}

TEST(LogTest, openPipe) {

    open_log();

    if(fork()==0){

        int fd = open_pipe();

        ASSERT_GT(fd, 0);

        close(fd);

        exit(EXIT_SUCCESS);
    }

    usleep(500);

    if(open(LOGPIPE, O_WRONLY)==-1){
        perror("test");
        exit(EXIT_FAILURE);
    }
}