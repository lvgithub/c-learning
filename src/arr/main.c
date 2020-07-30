#include <stdio.h>

int main()
{
    char greeting[] = "hello";

    printf("Greeting message: %s\n", greeting);
    printf("Greeting message length: %lu\n", sizeof(greeting));
    return 0;
}