#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int *data = (int *) malloc(sizeof(int) * 100);
    data[100] = 2;
    return 0;
}
