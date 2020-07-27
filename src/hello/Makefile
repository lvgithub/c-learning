clean: build 
	rm -rf *.o 

# build: clean hello.c
# 	gcc -o hello.out hello.c

# 用来表示生所有的以 .c 结尾的文件。
build: *.c
	@# $@ 表示的是构建的目标名称，也就是 build
	@# 如下写入等于 gcc -o test $^
	@# $< 指代第一个前置条件。比如，规则为 t: p1 p2，那么$< 就指代p1. 如下案例指的是  *.c 所匹配的文件及hello.c
	$(CC) -o hello $^ 
	




