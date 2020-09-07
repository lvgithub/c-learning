#include <stdio.h>
#include <string.h>

int main()
{
    int arr[3] = {1, 2, 3};

    printf("数组变量是一个指针 arr : %d \n", *arr);
    printf("数组变量是数组元素的第一个值的地址 arr+1: %d \n", *(arr + 1));

    return 0;
}