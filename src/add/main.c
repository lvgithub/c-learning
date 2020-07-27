#include <stdio.h>
#include "add.h"

/*定义两个全局变量*/
int x = 1;
int y = 2;

int main(void)
{
    int result;
    result = add();
    printf("result 为: %d\n", result);
    printf("\a");

    const int xx = 1;
    int const bb = 2;
    printf("xx,%d\n", xx);
    printf("bb,%d\n", bb);
    return 0;
}