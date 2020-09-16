

# 你可能没留意到的大坑 [内存污染]

**背景**

我们定义一个变量A，修改另外一个一个变量B，导致A的值被修改，我们称它为内存污染。



**案例**

如下程序，正常的预期输出应该是: `97 98 256`,但正确的结果却是`1 0 256`，意不意外，惊不惊喜

这时候主要问题发生在   `int *ptr = (int *)&b;`这里，对`&b`强类型转换,污染了 `a`的内存

`a` 的地址比`b`地址大(**堆从低到高, 栈从高到低分配地址**)

```c
#include <stdio.h>

int main(void)
{
    char a = 'a', b = 'b';

    int *ptr = (int *)&b;
    *ptr = 256;

    printf("%d,%d,%d \n", a, b, *ptr); // 1 0 256
    return 0;
}
```

**验证**

我们通过gdb调试，打印出各个变量的地址

```shell
$ gdb a.out 
(gdb) b 7
Breakpoint 1 at 0x100000f47: file test.c, line 7.
(gdb) b 11
Breakpoint 2 at 0x100000f77: file test.c, line 11.

Thread 2 hit Breakpoint 1, main () at test.c:7
7           int *ptr = (int *)&b;
(gdb) x/1tb &a
0x7ffeefbff55b: 01100001
(gdb) x/1tb &b
0x7ffeefbff55a: 01100010
(gdb) n
8           *ptr = 256;
(gdb) n
10          printf("%d,%d,%d \n", a, b, *ptr); // 1 0 256
(gdb) n
1,0,256 

Thread 2 hit Breakpoint 2, main () at test.c:11
11          return 0;
(gdb) x/1tb &a
0x7ffeefbff55b: 00000001
(gdb) x/1tb &b
0x7ffeefbff55a: 00000000
(gdb) x/4tb ptr
0x7ffeefbff55a: 00000000        00000001        00000000        00000000
```

我们在`*ptr = 256;`这里打了断点，然后分别看执行前后`a`,`b`的变化

我们先在断点前，使用gdb命令 `x/1tb &a`查看内存

* `a`的地址 `0x7ffeefbff55b` 值为十进制 `97`
* `b`的地址 `0x7ffeefbff55a` 值为十进制 `98`

结论：** `a` 的地址比 `b` 的地址高**

```
(gdb) x/1tb &a
0x7ffeefbff55b: 01100001
(gdb) x/1tb &b
0x7ffeefbff55a: 01100010
```

然后我们执行`*ptr = 256;`这句后，再次查看

```shell
(gdb) x/1tb &a
0x7ffeefbff55b: 00000001
(gdb) x/1tb &b
0x7ffeefbff55a: 00000000
(gdb) x/4tb ptr
0x7ffeefbff55a: 00000000        00000001        00000000        00000000
```

ptr赋值245后，内存中值为 `00000000    00000001    00000000    00000000`

直接污染了 `a` 的内存,把 `a` 值修改为了 `00000001` 因为ptr为 `int*` 类型，占用4个字节，`a`的地址比 `ptr` 高1，属于4个字节之内，所以被污染了。 

