# 事件循环

事件循环是libuv功能的核心部分，它负责轮询i/o，并根据不同的事件源调度要运行的回调。



#### 事件循环数据类型（Loop data type）

[struct uv_loop_s 源码](https://github.com/libuv/libuv/blob/cbcd0cfc824c712f6068930507a34d6b80e33b29/include/uv.h#L1780)

```c
struct uv_loop_s {
  /* User data - use this for whatever. */
  void* data;
  /* Loop reference counting. */
  unsigned int active_handles;
  void* handle_queue[2];
  union {
    void* unused;
    unsigned int count;
  } active_reqs;
  /* Internal storage for future extensions. */
  void* internal_fields;
  /* Internal flag to signal loop stop. */
  unsigned int stop_flag;
  UV_LOOP_PRIVATE_FIELDS
};
```

