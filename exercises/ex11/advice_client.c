/* Client that talks to advice_server.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 30000

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

// Using code from Project 2: https://github.com/shrutiyer/SoftSysServerClient/blob/master/source/client.c
int open_socket()
{
    int sock_fd;
    struct sockaddr_in server_address;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    int connect_val = connect(sock_fd, (const struct sockaddr *)&server_address, sizeof(server_address));
    if (connect_val < 0) {
        perror("Connection failure");
        exit(EXIT_FAILURE);
    }
    return sock_fd;
}

int say(int socket, char *s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        error("Can't talk to the server");

    return result;
}

int main(int argc, char *argv[])
{
    int d_sock, bytes_received;
    char buf[255], rec[256];

    /* connect to server */
    d_sock = open_socket();

    /* send host name and required blank line */
    say(d_sock, "Gimme some bad advice!\r\n");

    /* display page on stdout in 255 byte chunks */
    bytes_received = recv(d_sock, rec, 255, 0);
    while (bytes_received) {
        if (bytes_received == EOF)
            error("can't read from server");

        rec[bytes_received] = '\0';
        printf("%s", rec);
        bytes_received = recv(d_sock, rec, 255, 0);
    }
    close(d_sock);

    return 0;
}
