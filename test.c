#include <stdio.h>

int main(void)
{
    char a = 'a', b = 'b';

    int *ptr = (int *)&b;
    *ptr = 256;

    printf("%d,%d,%d \n", a, b, *ptr); // 1 0 256
    return 0;
}