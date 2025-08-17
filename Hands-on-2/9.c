#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int main()
{
        /*Program to ignore SIGINT, then reset its default action*/
        signal(SIGINT,SIG_IGN);
        printf("Ignoring SIGINT . . . .\n");
        sleep(5);
        printf("No SIGINT within 5 seconds\n");

	/*Default action:*/
	signal(SIGINT,SIG_DFL);
	printf("Default action for SIGNINT . . . .");
	sleep(5);
	printf("No SIGINT within 5 seconds.");
        return 0;
}

