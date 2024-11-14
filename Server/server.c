#include "../common/common.h"

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket failed");
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("setsockopt");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the network address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("bind failed");
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        error("listen");
    }

    printf("Server listening on port %d\n", PORT);

    // Accepting a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        error("accept");
    }

    // Reading and responding to client messages
    while (1) {
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) break;
        printf("Received: %s\n", buffer);
        send(new_socket, buffer, valread, 0);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
