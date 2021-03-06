

## C语言指针

本文不讲基础，重点是总结，基础知识参考 [基础概念](http://c.biancheng.net/view/1990.html)

**介绍**

* 内存中每个字节都有一个地址，整个内存是有序排列的，地址从0依次增加,指针可以通过地址和类型来解析出数据
* 指针也是变量（对内存区域的抽象），不过存储的是一个内存地址，`指针类型`告诉编译器去访问那块内存时，该如何解析那块内存，是int、chat、float...



**本质**

* 定义一个整形指针`int *p = &a;`  p 指向一个内存地址，int表示需要解析4个字节
* 定义一个整形指针`int *c = &b;`  p 指向一个内存地址，char 表示需要解析1个字节

```c
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
```

<img src="assets/readme/image-20200913102148226.png" alt="image-20200913102148226" style="zoom:50%;" />

上图表示的是指针在内存中的布局，指针由`*` + `地址`+`类型`

`* ` 表示是一个指针 

`地址` 表示变量在内存中起始地址

`类型` 表示要从内存中解析几个字节单元



**运算**

指针变量+1，并不是真的加1，而是加1*sizeof(指针类型)

```C
#include <stdio.h>

int main()
{	
    int a = 1;
    int *p = &a;

    printf("%p \n", p);       //0x7ffedffb45cc
    printf("%p \n", (p + 1)); //0x7ffedffb45d0
}
```

可以发现， `p+1` 和 `p`  刚好相差`4 Byte`，及`sizeof(a)`  的长度



**精髓**

* 通过指针能实现所谓的“传引用”而不是“传值”，本质上节约了数据传输性能
* 指针的运算（对指针加减，甚至取指针）才是c类语言强大的地方

**函数指针**

* 函数指针是指向函数的指针变量，我们可以把函数指针作为参数，作为另外一个函数的回调函数使用，这在异步编程中有着非常重要的意义
* 比如`qsort(void base, size_t nitems, size_t size, int (compar)(const void *, const void*))`compar 作为回调函数，来比较数组。

```c
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
```



**缺点**

* 指针、无越界检查等等是一切痛苦的根源



