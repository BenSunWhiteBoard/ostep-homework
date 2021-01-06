#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int     fd[2], nbytes;
    pid_t   receive_pid;
    pid_t  send_pid;
    char    string[] = "Hello, world!\n";
    char    readbuffer[80];

    pipe(fd);

    send_pid = fork();

    if (send_pid < 0){
        perror("fork");
        exit(1);
    }

    if (send_pid == 0) {
        /* process send  */
        printf("\t hello, I am child (pid:%d) that write pipe\n", (int)getpid());

        /* process closes up input side of pipe */
        close(fd[0]);

        /* Send "string" through the output side of pipe */
        write(fd[1], string, (strlen(string)+1));

        printf("\t child(%d) about to finish\n", (int)getpid());
    } else {
        receive_pid = fork();

        if (receive_pid < 0){
            perror("fork");
            exit(1);
        }

        if (receive_pid == 0) {
            /* process receive */
            printf("\t\t hello, I am child (pid:%d) that read pipe\n", (int)getpid());

            /* input process closes up output side of pipe */
            close(fd[1]);

            /* Read in a string from the pipe */
            nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
            printf("\t\t Received string: %s", readbuffer);
            printf("\t\t child(%d) about to finish\n", (int)getpid());

        } else {
            /* Parent process */
            printf("hello, I am parent (pid:%d)\n",(int)getpid());

            printf("parent about to finish\n");
        }
    }

    return 0;
}