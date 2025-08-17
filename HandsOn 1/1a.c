#include <stdio.h>
#include <unistd.h>

int main()
{
    int r;
    r = symlink("/home/OneDrive/Sem4/OS/Assignments/Lab/Hands-on-1/1a", "/home/OneDrive/Sem4/OS/Assignments/Lab/Hands-on-1/links/link1a_c");
    printf("Symlink returns %d\n",r);
}