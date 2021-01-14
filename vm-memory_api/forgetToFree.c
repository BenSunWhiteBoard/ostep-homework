#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int *ptr = (int*) malloc(sizeof(int)*20);
    ptr[0] = 20;
    //not free it
    return 0;
}
