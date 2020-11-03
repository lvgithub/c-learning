libuv 学习

## 编译libuv
```
git clone libuv 源码
cd ./libuv
```

```
./autogen.sh
./configure
make
```
执行完成后，会在libuv源码目录生成 .libs 文件夹，里面有很多文件，最重要的是 libuv.a 静态链接库。也就是我们后面会用到的。

## 链接libuv编译程序
```
gcc hello.c .libs/libuv.a -lpthread
```



## 参考
* [libuv编译最佳实践](https://zhuanlan.zhihu.com/p/31344416)