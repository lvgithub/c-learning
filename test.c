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
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[10];

    // 定义一个函数指针
    int (*pfun)(void) = NULL;
    pfun = genRandomValue;

    // 函数指针作为回调函数
    fillArray(arr, 10, pfun);
    printArr(arr, sizeof(arr) / sizeof(arr[0]));

    // 对数组进行排序
    qsort(arr, 10, sizeof(int), compare);
    printArr(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}