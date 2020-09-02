#include <stdio.h>

int main()
{

    int a[10] = {1, 4, 54, 6, 57, 3};

    int *p1;
    int(*p2)[10];

    // a 隐式转换为指针 int*
    p1 = a;
    // p2 为数组指针 int (*)[10]
    p2 = &a;

    // a 和&a 都指向相同的地址，不过他们两的类型不一样
    printf("%p\n", a);
    printf("%p\n", &a);

    // 这时候 a 不会发生隐式转换，打印数组的长度: 40
    printf("%lu \n", sizeof(a));
    // 打印的是指针的长度： 8
    printf("%lu \n", sizeof(p1));

    // 打印出数组第一个元素的值 （a是数组第一个元素的地址）
    printf("%d \n", *a);
    // 打印第二个值 4，这时候a是数组
    printf("%d \n", a[1]);

    // 打印第二个值 4，这时候a是指针
    printf("%d \n", *(a + 1));

    //打印指针（*p）的值，*p 是数组第一个元素的地址
    printf("%d \n", **p2);
    //打印数组第二个元素的值，*p2+1 是数组第二个元素的地址
    printf("%d \n", *(*p2 + 1));

    return 0;
}
