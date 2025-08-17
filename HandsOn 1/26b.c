#include <stdio.h>
#include <unistd.h>
int main()
{
    static char *argv[] = {"/bin/ls", "-l",NULL};
    execv(argv[0], argv);
    return 0;
}
