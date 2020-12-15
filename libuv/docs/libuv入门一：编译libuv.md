

 `libuv`入门一: 编译libuv 

Libuv 源码地址 [github](https://github.com/libuv/libuv)



## 编译

下载源码，进入跟目录，编译:

```shell
$ sh autogen.sh
$ ./configure
$ make
$ make check
$ make install
```

`make`生成`.libs`目录，里面是编译好的静态库，核心是 `libuv.a `文件。

```shell
.
├── libuv.1.dylib
├── libuv.a
├── libuv.dylib -> libuv.1.dylib
├── libuv.la -> ../libuv.la
└── libuv.lai
```

`make install`会把：

*  `uh.h`头文件复制到`/usr/local/include/`
* libuv.a 复制到 `/usr/local/lib`

所以`install`后,加`-luv` 参数，指定`uv`库，就可以直接编译程序

```shell
gcc hello.c -luv
```

如果为了更好的可移植性，把源码集成到项目编译，然后直接使用编译生成的`静态库`

```shell
gcc hello.c -Iinclude ./.libs/libuv.a 
```

* `-Iinclude` : 指定头文件去 `include`目录查找
* `./.libs/libuv.a`: 静态库路径 

`include`目录

```shell
.
├── uv
│   ├── aix.h
│   ├── android-ifaddrs.h
│   ├── bsd.h
│   ├── darwin.h
│   ├── errno.h
│   ├── linux.h
│   ├── os390.h
│   ├── posix.h
│   ├── stdint-msvc2008.h
│   ├── sunos.h
│   ├── threadpool.h
│   ├── tree.h
│   ├── unix.h
│   ├── version.h
│   └── win.h
└── uv.h
```



## `-luv` -l后面为什么是uv？
libuv的文件名是libuv.a。前缀lib和后缀.a是标准的，uv是基本名称，GCC 会在-l选项后紧跟着的基本名称的基础上自动添加这些前缀、后缀，本例中，基本名称为uv。

