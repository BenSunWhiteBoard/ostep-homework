#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "usage: ./memory-user <memory> <loop_circles>\n");
        exit(EXIT_FAILURE);
    }

    printf("pid: %d\n", getpid());

    // memory is in MB
    int memory = atoi(argv[1]) * 1024 * 1024;
    int length = (int)(memory / sizeof(int));
    int loop_circles = atoi(argv[2]);
    int *arr = malloc(memory);

    while (loop_circles > 0)
    {
        for (int i = 0; i < length; i++)
            arr[i] += 1;
        loop_circles--;
    }

    free(arr);
    return 0;
}