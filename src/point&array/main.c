#include <stdio.h>
#include <string.h>

int main()
{
    char *str = "123";
    printf("the value of str is %s \n", str);
    printf("the first value of str is %c \n", *str);

    char str2[4] = {'1', '2', '3'};

    printf("the length of str2 is %lu \n", sizeof(str2));
    printf("the value of str2 is %s \n", str2);
    printf("the first of str2 is %c \n", *str2);
    printf("the second of str2 is %c \n", *(str2 + 1));

    char str3[] = "123";
    printf("the value of str3 is %s \n", str3);
    printf("the second of str2 is %c \n", *(str++));

    char a[5] = {'A', 'B', 'C', 'D'};
    char(*p3)[5] = &a;
    char(*p4) = a;

    return 0;
}