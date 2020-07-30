#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    // int a = 1;
    // int b = 2;
    // int *intP = &a;

    // intP = &b;
    // printf("intP %d\n", *intP);

    int (*p)(int, int) = &max;
    int result = (*p)(1, 2);
    printf("result %d\n", result);
}