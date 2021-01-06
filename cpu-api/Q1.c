#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int x = 20;
    int rc = fork();
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("x in child process: %d\n", x);
        x = 22;
        printf("child change x to:%d\n", x);
    }
    else
    {
        // parent goes down this path (main)
        printf("x in parent process: %d\n", x);
        x = 25;
        printf("parent change x to:%d\n", x);
    }
    return 0;
}
