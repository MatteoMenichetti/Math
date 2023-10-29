#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SOCKPATH "../tmp/socket"

struct numbers {int n; struct numbers *  next;};