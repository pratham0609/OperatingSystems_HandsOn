#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
    struct sockaddr_in server, client;
    unsigned int sd, sz, nsd; 
    char buf[80];             

    sd = socket(AF_UNIX, SOCK_STREAM, 0); 

    server.sin_family = AF_UNIX;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htonl(5555); 
    bind(sd, (struct sockaddr *)&server, sizeof(server));

    listen(sd, 2); 

    while (1)
    {
        sz = sizeof(client);

        if ((nsd = accept(sd, (struct sockaddr *)(&client), &sz)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (!fork())
        {
            close(sd);
            read(nsd, buf, sizeof(buf));
            printf("Meassge from client : %s\n", buf);
            write(nsd, "ACK FROM SERVER\n", sizeof("ACK FROM SERVER\n"));
            getchar();
            exit(0);
        }

        else
            close(nsd);
    }
}
