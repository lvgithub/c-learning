# 设计概述

libuv是一个围绕事件驱动的异步I/O模型设计的跨平台的支持库，最初只是为Node.js而写。 该库提供了对IO和实体的抽象核心有两个对象：

* handles:  表示一个`持久`的对象,在激活期间可以执行一系列操作。例如一个`TCP handles`。新连接了一个`TCP`连接就是一个`TCP handles`,只要连接没断开，这个`TCP handles`就会一直处于激活状态。
* requests：表示短暂的操作，这些操作在`handle`上执行，比如写`request`通过句柄上写入数据，然后应答，这个`requset`就完成了。便不是所有的`request`都必须在`handle`中完成，例如`getaddrinfo`是不依赖`handle`的。

```c
/* Handle types. */
typedef struct uv_loop_s uv_loop_t;
typedef struct uv_handle_s uv_handle_t;
typedef struct uv_dir_s uv_dir_t;
typedef struct uv_stream_s uv_stream_t;
typedef struct uv_tcp_s uv_tcp_t;
typedef struct uv_udp_s uv_udp_t;
typedef struct uv_pipe_s uv_pipe_t;
typedef struct uv_tty_s uv_tty_t;
typedef struct uv_poll_s uv_poll_t;
typedef struct uv_timer_s uv_timer_t;
typedef struct uv_prepare_s uv_prepare_t;
typedef struct uv_check_s uv_check_t;
typedef struct uv_idle_s uv_idle_t;
typedef struct uv_async_s uv_async_t;
typedef struct uv_process_s uv_process_t;
typedef struct uv_fs_event_s uv_fs_event_t;
typedef struct uv_fs_poll_s uv_fs_poll_t;
typedef struct uv_signal_s uv_signal_t;

/* Request types. */
typedef struct uv_req_s uv_req_t;
typedef struct uv_getaddrinfo_s uv_getaddrinfo_t;
typedef struct uv_getnameinfo_s uv_getnameinfo_t;
typedef struct uv_shutdown_s uv_shutdown_t;
typedef struct uv_write_s uv_write_t;
typedef struct uv_connect_s uv_connect_t;
typedef struct uv_udp_send_s uv_udp_send_t;
typedef struct uv_fs_s uv_fs_t;
typedef struct uv_work_s uv_work_t;
```

I/O 事件循环是`libuv`的核心，事件循环建立起异步I/O操作的核心内容，I/O操作会注册到事件循环中，事件循环会轮询已经`readable, writable hangup`的事件，并且触发执行回调函数。

`File I/O`和`Network I/O`不一样,由于没有可依赖的异步`File I/O`原语，因此，当前的方法是在线程池中运行阻塞文件I/O操作。因此libuv将维护一个线程池，线程池中可能创建了多个线程并阻塞它们。

为了更好的理解事件循环，请看下图：

![image-20201124165046476](https://raw.githubusercontent.com/lvgithub/bos/master/uPic/image-20201124165046476.png)

1. `Update loop time `  更新loop time 为现在时间，在事件循环计时开始时缓存当前时间，以减少与时间相关的系统调用数。这个时间会用于判断`setTimemout`等设置的回调函数是否需要触发。

2. ` loop alive？`  判断事件循环是否处于活动状态,如果连`handle` 、`request`都没有，就没必要继续执行事件循环。

    ```c
    static int uv__loop_alive(const uv_loop_t* loop) {
      return uv__has_active_handles(loop) ||
             uv__has_active_reqs(loop) ||
             loop->closing_handles != NULL;
    }
    ```

3. `Run due timers `  执行到期计时器,处于1阶段更新的时间之前，也就是到期了的计时器的`callback`将会被回调。

4. `Run pending callbacks`  执行被挂起的回调函数，调用回调被推迟到下一个循环迭代。例如：如果 TCP 套接字在尝试连接时接收到 `ECONNREFUSED`，这将被排队以在这个阶段执行。

5. `Run idle handles`     每个循环迭代中都会运行一次,该阶段可以用来执行一些优先级较低的活动，比如发送性能日志等。如果改阶段有需要执行的回调函数，`Poll for I/O`阶段将不会阻塞，比如使用事件循环下载文件，如果`Poll for I/O`阶段阻塞，将会造成下载终端。但是如果通过改阶段来下载文件，可以保证`Poll for I/O`接口不阻塞。

6. `Run prepare handles`  会在 `poll for I/O.`  阶段之前执行，如果你想在I/O之前执行某个参数，就可以在该阶段去执行

7. 



















