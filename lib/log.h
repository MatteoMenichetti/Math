#include "common.h"

#define LOGPATH "../log/general.log"

ssize_t write_on_log(char *, int);

void open_log();

int open_pipe();

void read_log_pipe(int);

void sigterm_handler(int);