// SERVER
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{

    struct timeval tmo;
    fd_set readfds;

    struct sockaddr_in server, client;
    unsigned int sd, sz, nsd; 
    int opt = 1;
    char buf[80];

    sd = socket(AF_UNIX, SOCK_STREAM, 0); 
    if (sd == 0)
    {
        perror("Socket Failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsocketopt");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_UNIX;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htonl(5555); 
    if (bind(sd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sd, 5) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    sz = sizeof(client);
    if ((nsd = accept(sd, (struct sockaddr *)(&client), &sz)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&readfds);
    FD_SET(nsd, &readfds);
    tmo.tv_sec = 3;
    tmo.tv_usec = 0;
    if (!select(nsd + 1, &readfds, NULL, NULL, &tmo))
    {
        printf("No Response from client\n");
        exit(0);
    }
    read(nsd, buf, sizeof(buf));
    printf("Message from client : %s\n", buf);

    write(nsd, "ACK from server\n", sizeof("ACK from server\n"));

    close(sd);
}
