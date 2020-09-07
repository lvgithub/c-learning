#include <stdio.h>
#include <string.h>

char *test1();
char *test2();
int main()
{
    printf(" %s \n", test1());
    printf(" %s \n", test2());

    char *p = "hello world";
    p = "hello c";

    // char pa[12] = "hello world";
    // array type 'char [12]' is not assignable
    // pa = "hello c";

    return 0;
}

char *test1()
{
    char *p = "hello world";
    return p;
}

char *test2()
{
    char p[] = "hello world";
    // warning: address of stack memory associated with local variable 'p' returned [-Wreturn-stack-address]
    return p;
}