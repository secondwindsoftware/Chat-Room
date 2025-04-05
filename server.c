#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
// create socket
int server_socket = socket(AF_INET, SOCK_STREAM, 0);
// bind socket to address and port
struct sockaddr_in server_address;
server_address.
sin_family = AF_INET;
server_address.
sin_port = htons(YOUR_PORT_NUMBER); 
server_address.sin_addr.
s_addr = INADDR_ANY;
bind(server_socket,
(struct sockaddr *)&server_address, sizeof(server_address));
// listen 
listen(server_socket,
5); 
// accept connections
int client_socket = accept(server_socket, NULL, NULL);
// client communication 
char buffer[1024];
while (1) {
int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
if (bytes_received <= 0) {
break;
}
// echo 
send(client_socket, buffer, bytes_received,
0);
}
// close
close(client_socket);
close(server_socket);