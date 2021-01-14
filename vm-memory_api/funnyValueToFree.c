#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int *data = (int *) malloc(sizeof(int) * 100);
    free(data + 5);
    return 0;
}
