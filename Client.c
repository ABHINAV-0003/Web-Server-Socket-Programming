#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
#define BUFFER_SIZE 1024
void send_request(const char *request) {
int sockfd;
struct sockaddr_in serv_addr;
char buffer[BUFFER_SIZE];
if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
perror("Socket creation error");
exit(EXIT_FAILURE);
}
memset(&serv_addr, '0', sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);
if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
perror("Invalid address/ Address not supported");
exit(EXIT_FAILURE);
}
if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
{
perror("Connection failed");
exit(EXIT_FAILURE);
}
if (send(sockfd, request, strlen(request), 0) < 0) {
perror("Send request failed");
exit(EXIT_FAILURE);
}
int bytes_received;
while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
buffer[bytes_received] = '\0';
printf("%s", buffer);
}
if (bytes_received < 0) {
perror("Receive failed");
exit(EXIT_FAILURE);
}
close(sockfd);
}
int main() {
printf("Sending GET request:\n");
send_request("GET / HTTP/1.1\r\nHost: localhost\r\nConnection:
close\r\n\r\n");
printf("\n\nSending POST request:\n");
send_request("POST / HTTP/1.1\r\nHost: localhost\r\nConnection:
close\r\nContent-Length: 0\r\n\r\n");
return 0;
}