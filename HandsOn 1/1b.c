#include <stdio.h>
#include <unistd.h>

int main()
{
    int r;
    r = link("/home/OneDrive/Sem4/OS/Assignments/Lab/Hands-on-1/1b", "/home/OneDrive/Sem4/OS/Assignments/Lab/Hands-on-1/links/link1b_c");
    printf("link returns %d\n",r);
}