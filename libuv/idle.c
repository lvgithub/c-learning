#include <stdio.h>
#include <uv.h>

int64_t counter = 0;

void wait_for_a_while(uv_idle_t *handle)
{
    counter++;
    printf("%lld", counter);
    if (counter >= 10e6)
        uv_idle_stop(handle);
}

int main()
{
    uv_idle_t idler;
    // 获取事件循环的核心结构体。并初始化一个idler
    uv_idle_init(uv_default_loop(), &idler);
    // 往事件循环的idle节点插入一个任务
    uv_idle_start(&idler, wait_for_a_while);
    // 启动事件循环
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
    // 销毁libuv的相关数据
    uv_loop_close(uv_default_loop());
    return 0;
}