## 指针和数组

* 数组的本质是对“一系列连续内存单元”的抽象；它对外表现为“一个固定大小的容器”
* 数组名不能作为左值是因为C语言规定数组操作时，要单个操作，不能整体操作
* 数组是编译器在内存中自动分配的，执行程序时就确定了大小和地址，无法修改
* 数组中各个元素的地址是依次相连的

```C++
#include <stdio.h>
#include <string.h>

int main()
{
    int a[3] = {1, 2, 3};

    printf(" %d \n", *a);
    printf(" %d \n", *(a + 1));

    printf(" %p \n", &a[0]);
    printf(" %p \n", &a);
    printf(" %d \n", sizeof(a));

    //error: 'int *' with an expression of type 'int (*)[3]'
    // int *p1 = &a;

    int (*p)[3] = &a;

    return 0;
}
```
运行结果如下:
```bash
 1 
 2 
 0x7ffee54be5bc 
 0x7ffee54be5bc
 12
```
结论:
* a 指向数组的首元素地址（一般情况下）
* a 可以像指针一样操作
* a 作为左值代表整个数组的所有空间，所以 a 不能作为左值
* &a 是指针数组的指针，类型为 int (*p)[3]，这种情况下 a 不能被看成是首元素的地址
* &a 和 &a[0] 虽然值相同，但是意义和类型不一样
* sizeof(a) 的情况下 a 不能被看成是首元素的地址
* int *p1 = &a 会直接报错， 'int *' with an expression of type 'int (*)[3]'

所以数组名称只有在被看为是数组首元素地址的时候，可以像操作指针一样操作。


字符指针和字符数组的区别
```C++
#include <stdio.h>
#include <string.h>

char *test1();
char *test2();
int main()
{
    printf(" %s \n", test1());
    printf(" %s \n", test2());

    char *p = "hello world";
    p = "hello c";

    char pa[12] = "hello world";
    // array type 'char [12]' is not assignable
    // pa = "hello c";

    return 0;
}

char *test1()
{
    char *p = "hello world";
    return p;
}

// warning: address of stack memory associated with local variable 'p' returned [-Wreturn-stack-address]
char *test2()
{
    char p[] = "hello world";
    return p;
}
```
运行结果如下
```
hello world 
 � 
```
结论
* 字符指针test1中，是一个指向常亮字符串地址的指针，字符数组，内存申请在堆上，返回直接返回，会报警告，返回了一个堆上的地址，函数运行结束会被释放
* 字符指针是一个左值，可以进行赋值
* 数组名是一个右值，表示一个数组，不允许被赋值
* 栈内存被释放，所以test2返回值，打印出了一个 � 


指针数组和数组指针
* 指针数组是数组 int *p[5]  []的优先级高于* 所以 p[5] 先结合成数组
* 数组指针是指针 int (*p)[5] ()使*和p先结合成指针

