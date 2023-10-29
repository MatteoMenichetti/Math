#include <stdio.h>
#include "../lib/common.h"

int initializationSOCKET(struct sockaddr_un *sock_server) {
    int socket_server_fd;

    strcpy(sock_server->sun_path, SOCKPATH);
    sock_server->sun_family = AF_UNIX;

    unlink(SOCKPATH);

    if ((socket_server_fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("server: socket");
        exit(EXIT_FAILURE);
    }

    if (bind(socket_server_fd, (struct sockaddr *) sock_server, sizeof(*sock_server)) == -1) {
        perror("server: bind");
        exit(EXIT_FAILURE);
    }

    if (listen(socket_server_fd, 1) == -1) {
        perror("server: listen");
        exit(EXIT_FAILURE);
    }

    return socket_server_fd;
}

int acceptSOCKET() {
    int asocket_server_fd;
    struct sockaddr_un sock_server, socket_client;
    int socket_server_fd = initializationSOCKET(&sock_server);
    unsigned int len = sizeof(socket_client);

    if ((asocket_server_fd = accept(socket_server_fd, (struct sockaddr *) &socket_client, &len)) == -1) {
        perror("input_manager: accept");
        exit(EXIT_FAILURE);
    }
    return asocket_server_fd;
}

int main(int argc, char ** argv){
    int fd = acceptSOCKET();

    return 0;
}