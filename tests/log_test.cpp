#include <gtest/gtest.h>

extern "C" {
#include "../src/log.c"
}

TEST(log_test, create_logfile){

    unlink(LOGPATH);

    open_log();

    ASSERT_NE(fd_log, -1);
}