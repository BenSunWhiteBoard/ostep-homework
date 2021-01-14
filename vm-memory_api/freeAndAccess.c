#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int *ptr = (int *) malloc(sizeof(int));
    ptr[0] = 10;
    free(ptr);
    int x = *ptr;
    return 0;
}
