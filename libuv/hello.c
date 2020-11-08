#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

#define QUEUE_INIT(q)      \
    do                     \
    {                      \
        printf("1 %d", q); \
    } while (0)
int main()
{
    uv_loop_t *loop = malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);
    QUEUE_INIT(1);
    printf("Now quitting.\n");
    uv_run(loop, UV_RUN_DEFAULT);

    uv_loop_close(loop);
    free(loop);
    return 0;
}