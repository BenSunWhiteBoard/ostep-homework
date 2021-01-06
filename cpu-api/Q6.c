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
        printf("\t hello, I am child (pid:%d)\n", (int)getpid());

        // printf("child waiting for parent to finish!\n");
        // int rc_wait = wait(NULL);
        // printf("wait() return value is: %d\n", rc_wait);

        printf("\t child about to finish\n");
    }
    else
    {
        // parent goes down this path (main)
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());

        printf("parent waiting for child to finish!\n");
        // pid_t waitpid(pid_t pid, int *status, int options);
        // pid:
        // < -1: Wait for any child process whose process group ID is equal to the absolute value of pid.
        // -1: Wait for any child process.
        // 0: Wait for any child process whose process group ID is equal to that of the calling process.
        // > 0: Wait for the child whose process ID is equal to the value of pid
        // status:
        // It is a pointer to integer in which waitpid() will store the new status. 
        // options: 
        // WNOHANG: Return immediately if no child has exited.
        // WUNTRACED: Also return if a child has stopped. Status for traced children which have stopped is provided even if this option is not specified.
        // WCONTINUED: Also return if a stopped child has been resumed by delivery of SIGCONT.
        int rc_wait = waitpid(0, 0, 0);
        printf("wait() return value is: %d\n", rc_wait);
        
        printf("parent about to finish\n");
    }
    return 0;
}