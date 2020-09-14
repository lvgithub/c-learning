#include <stdio.h>

int main()
{
    int a = 1;
    int *p = &a;

    printf("%p \n", p);       //0x7ffee38075c8
    printf("%p \n", (p + 1)); //0x7ffee38075cc
}
