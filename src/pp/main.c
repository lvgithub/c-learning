#include <stdio.h>

// 二级指针
int main()
{
    int x = 9;
    int *pi;
    int **ppi;
    pi = &x;

    ppi = &pi;

    printf("x:，%d", **ppi);
}