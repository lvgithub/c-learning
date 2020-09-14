#include <stdlib.h>
#include <stdio.h>

void fillArray(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
        array[i] = getNextValue();
}

int genRandomValue(void)
{
    return rand() % 10;
}

int main(void)
{
    int arr[10];

    // 定义一个函数指针
    int (*pfun)(void) = NULL;
    pfun = genRandomValue;

    // 函数指针作为回调函数
    fillArray(arr, 10, pfun);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}