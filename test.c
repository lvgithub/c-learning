#include <stdio.h>
#include <string.h>

int main()
{
    int a = 100;
    int *p = &a;

    char b = 'c';
    char *c = &b;

    printf("%d \n", *p);
    printf("%c \n", *c);
}
