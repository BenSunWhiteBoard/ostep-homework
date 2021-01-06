#include <stdio.h>
#include <stdlib.h>
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
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        // int execlp(const char *file, const char *arg, ...);
        // file: name of program to execute
        // first argument:point to the filename associated with the file being executed 
        // last argument: NULL
        // execlp("ls","ls",NULL);

        // int execvp(const char *file, char *const argv[]);
        // argv[]: argument vector, no fist file name convention
        // char *const cmd[] = {"ls", NULL};
        // execvp("ls",cmd);

        // int execv(const char *path, char *const argv[]);
        // path: The path to the new program executable.
        // char *const cmd[] = {"ls", NULL};
        // execv("/bin/ls",cmd); 

        char *const cmd[] = {"echo","this is command", NULL};
        char *const extra[] = {NULL};
        execve("/bin/echo",cmd, extra);

        printf("shouldn't print out");
    }
    else
    {
        // parent goes down this path (main)
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
    }
    return 0;
}