libuv 队列实现分析一



## libuv 通过宏实现的队列 

[源码链接](https://github.com/libuv/libuv/blob/48cf8c8286ec24925b9939ccf72a4fbdc3a57626/src/queue.h#L24)

```c
typedef void *QUEUE[2];

/* Private macros. */
#define QUEUE_NEXT(q)       (*(QUEUE **) &((*(q))[0]))
#define QUEUE_PREV(q)       (*(QUEUE **) &((*(q))[1]))
#define QUEUE_PREV_NEXT(q)  (QUEUE_NEXT(QUEUE_PREV(q)))
#define QUEUE_NEXT_PREV(q)  (QUEUE_PREV(QUEUE_NEXT(q)))
....
#define QUEUE_INIT(q)                                                         \
  do {                                                                        \
    QUEUE_NEXT(q) = (q);                                                      \
    QUEUE_PREV(q) = (q);                                                      \
  }                                                                           \
  while (0)

#define QUEUE_ADD(h, n)                                                       \
  do {                                                                        \
    QUEUE_PREV_NEXT(h) = QUEUE_NEXT(n);                                       \
    QUEUE_NEXT_PREV(n) = QUEUE_PREV(h);                                       \
    QUEUE_PREV(h) = QUEUE_PREV(n);                                            \
    QUEUE_PREV_NEXT(h) = (h);                                                 \
  }                                                                           \
  while (0)
```

### 理解 QUEUE_NEXT宏

首先 QUEUE 是一个包含两个`void * `指针的数组  `typedef void *QUEUE[2];`

然后看下最重要的一个宏：

`#define QUEUE_NEXT(q)       (*(QUEUE **) &((*(q))[0]))`

他的作用是返回下一个节点`QUEUE`的指针,我们分拆理解下这个`宏`：

参数`q` 是一个 QUEUE一个节点的地址，具体参考[源码](https://github.com/libuv/libuv/blob/48cf8c8286ec24925b9939ccf72a4fbdc3a57626/src/unix/loop.c#L50)的入参

```c
  QUEUE_INIT(&loop->wq);
  QUEUE_INIT(&loop->idle_handles);
```

然后我们把宏分解为4部分

1. `*(q)` :对`&loop->wq`解引用
2. `(*(q))[0]` : 取出 `q` 的首元素
3. `&((*(q))[0]))`: 对首元素取地址操作
4. `(QUEUE **)&((*(q))[0]))`： 因为`q`数组存储的是`void *`指针，再`&` ，所以需要使用二级指针`QUEUE **`进行强制转化
5. ` (*(QUEUE **) &((*(q))[0]))`:  再通过`*` 解引用，获的了 `q[0]`的指针

为什么要这样做呢？

* 如果我们直接进行`(QUEUE *)q[0]`这样得到的是一个右值，我们不能对他进行赋值操作。

```c
//这样会报错。
int a = 1; 
(char) a = 2;

//这样正确：
int a = 1; 
(*(char *)(&a)) = 2;
```



























