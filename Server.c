#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080
void handle_request(int client_socket) {
char response[1024] = {0};
char request[1024] = {0};
ssize_t read_size = read(client_socket, request, sizeof(request) - 1);
if (read_size < 0) {
perror("read");
return;
}
request[read_size] = '\0';
printf("\nReceived: %s\n", request);
if (strncmp(request, "GET", 3) == 0) {
sprintf(response, "HTTP/1.1 200 OK\nContent-Type:
text/html\n\n<html><body><h1>Name: ABHINAV RAJ V \n</h1><h2>Roll number:
B210759EC </h2></body></html>");
}
else if (strncmp(request, "POST", 4) == 0) {
sprintf(response, "HTTP/1.1 200 OK\nContent-Type:
text/html\n\n<html><body><h1> POST request received </h1></body></html>");
}
else {
sprintf(response, "HTTP/1.1 405 Method Not Allowed\nContent-Type:
text/html\n\n<html><body><h1>Method Not Allowed</h1></body></html>");
}
send(client_socket, response, strlen(response), 0);
}
int main() {
int server_fd, client_socket;
struct sockaddr_in address;
int addrlen = sizeof(address);
if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
perror("socket failed");
exit(EXIT_FAILURE);
}
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(PORT);
if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
perror("bind failed");
exit(EXIT_FAILURE);
}
if (listen(server_fd, 3) < 0) {
perror("listen");
exit(EXIT_FAILURE);
}
printf("Server listening on port %d...\n", PORT);
while (1) {
if ((client_socket = accept(server_fd, (struct sockaddr *)&address,
(socklen_t *)&addrlen)) < 0) {
perror("accept");
continue;
}
handle_request(client_socket);
close(client_socket);
}
return 0;
}