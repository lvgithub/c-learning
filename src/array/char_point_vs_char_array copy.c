#include <stdio.h>

void foo1(int *b);
void foo2(int c[]);

int main()
{

    int a[10] = {1, 4, 54, 6, 57, 3};

    int *p1;
    int(*p)[10];

    p1 = a;
    p = &a;

    printf("%lu \n", sizeof(p));
    printf("%lu \n", sizeof(p1));

    printf("%p \n", a);
    printf("%p \n", &a);

    printf("%p \n", p1);
    printf("%p \n", p);

    printf("%d \n", p1[1]);
    printf("%d \n", (*p)[1]);
    printf("%d \n", *(*p + 1));
    printf("%d \n", *(*p + 2));

    int a1[5]; // 5 x 4 = 20 Bytes
    foo1(a1);  // -> 8 Bytes
    foo2(a1);  // -> 8 Bytes

    return 0;
}

void foo1(int *b)
{
    printf("%lu\n", sizeof(b));
}

void foo2(int c[])
{
    printf("%lu\n", sizeof(&c));
}