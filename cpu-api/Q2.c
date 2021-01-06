#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int file_descriptor = open("./Q2.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
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
        printf("child has file_descriptor = %d\n", file_descriptor);
        write(file_descriptor, "this is message from child\n", strlen("this is message from child\n"));
    }
    else
    {
        // parent goes down this path (main)
        printf("parent has file_descriptor = %d\n", file_descriptor);
        write(file_descriptor, "this is message from parents\n", strlen("this is message from parents\n"));
    }
    return 0;
}
