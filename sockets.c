#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

#define IP "172.217.26.35" /* www.google.se */
#define PORT 80            /* http*/

int main()
{
    int s;

    struct sockaddr_in sock;

    s = socket(AF_INET, SOCK_STREAM, 0);

    if (s < 0)
    {
        printf("Socket error");
        return -1;
    }

    sock.sin_addr.s_addr = inet_addr(IP);
    sock.sin_port = htons(PORT);
    sock.sin_family = AF_INET;

    if (connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr_in)) != 0)
    {
        printf("connect() error");
        close(s);

        return -1;
    }
    return 0;
}