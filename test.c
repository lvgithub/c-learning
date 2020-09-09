#include <stdio.h>
#include <string.h>

char *test1();
char *test2();
int main()
{
    char str[] = "hello";

    printf("%lu \n", sizeof(str));
    printf("%lu \n", sizeof(str[0]));
    printf("%lu \n", strlen(str));
}
