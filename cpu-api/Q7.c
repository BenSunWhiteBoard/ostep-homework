#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
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
        printf("\thello, I am child (pid:%d)\n", (int)getpid());

        close(STDOUT_FILENO);
        printf("\tthis is message after close standard output");

        // printf("\tchild about to finish\n");
    }
    else
    {
        // parent goes down this path (main)
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());

        // printf("parent waiting for child to finish!\n");
        // int rc_wait = wait(NULL);
        // printf("wait() return value is: %d\n", rc_wait);
        
        printf("parent about to finish\n");
    }
    return 0;
}