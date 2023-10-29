#include <stdio.h>
#include "../lib/common.h"

int definesocket() {
    int client_socket_fd;
    if ((client_socket_fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("P2: socket");
        exit(EXIT_FAILURE);
    }
    return client_socket_fd;
}

void connecting(int client_socket_fd) {
    struct sockaddr_un sock_server;
    strcpy(sock_server.sun_path, SOCKPATH);
    sock_server.sun_family = AF_UNIX;
    while ((connect(client_socket_fd, (struct sockaddr *) &sock_server, sizeof(sock_server))) == -1) {
        perror("P2: connect");
        sleep(1);
    }
}

int main(int argc, char ** argv){

    return 0;
}