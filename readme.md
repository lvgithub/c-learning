## C语言一步一步深入

工作了很多年后，越发觉得C语言的重要性，虽然使用的JAVA,Node.JS,GO等等语言，但是当需要解决深入的问题的时候，或者想了解底层的实现原理，都离不开C语言。
比如Node.js想更好的了解它，做些好用的中间件，那必然需要了解libuv,学习libuv的基础就是C语言。因此决定重头再来，从最基础开始一步一步了解C语言。

## 编译器
GCC（GNU Compiler Collection，GNU编译器套装），是一套由GNU开发的编程语言编译器,它可以编译C、C++、JAV、Fortran、Pascal、Object-C、Ada等语言。
gcc是GCC中的GUN C Compiler（C 编译器）,我们将使用它来编译我们的源码

## 知识点
* LLVM: 不是一个编译器，也不是一个编译器后端，它是一个编译器基础设施框架，它包含了为我们编写编译器一系列的库（如程序分析、代码优化、机器代码生成等），并且提供了调用这些库的相关工具。
* Clang: 基于LLVM的编译器
* [Makefile](http://c.biancheng.net/view/7097.html): 可以使得我们的项目工程的编译变得自动化，不需要每次都手动输入一堆源文件和参数
* [CMake](https://www.hahack.com/codes/cmake/): 它首先允许开发者编写一种平台无关的 CMakeList.txt 文件来定制整个编译流程，然后再根据目标用户的平台进一步生成所需的本地化 Makefile 和工程文件
* 静态链接:
* 动态链接:
* 自动链接: