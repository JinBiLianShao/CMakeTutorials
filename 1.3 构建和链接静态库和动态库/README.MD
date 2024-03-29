#### 1.3 构建和链接静态库和动态库

------

> 项目中会有单个源文件构建的多个可执行文件的可能。项目中有多个源文件，通常分布在不同子目录
> 中。这种实践有助于项目的源代码结构，而且支持模块化、代码重用和关注点分离。同时，这种分离可
> 以简化并加速项目的重新编译。本示例中，我们将展示如何将源代码编译到库中，以及如何链接这些
> 库。

#### 具体实施

------

1. 创建目标——静态库。库的名称和源码文件名相同，具体代码如下：

```cmake
add_libraries(message
	STATIC
	Message.h
	Message.cpp
)
```

2. 创建 hello-world 可执行文件的目标部分不需要修改：

   ```cmake
   add_executable(hello-world hello-world.cpp)
   ```

3. 最后，将目标库链接到可执行目标：

   ```cmake
   target_link_libraries(hello-world messgae)
   ```

#### 编译

------

``` shell
$ mkdir build && cd build
$ cmake ..
$ cmake --build .

[ 50%] Built target message
Scanning dependencies of target hello-world
[ 75%] Building CXX object CMakeFiles/hello-world.dir/hello-world.cpp.o
[100%] Linking CXX executable hello-world
[100%] Built target hello-world

$ ls	# 可以看到生成了 libmessage.a 静态库和可执行文件 hello-world
CMakeCache.txt  CMakeFiles  cmake_install.cmake  hello-world  libmessage.a  Makefile

$ ./hello-world
This is my very nice message:
hello, CMake World!
This is my very nice message:
Goodbye, CMake World!
```

#### 工作原理

------

**add_library(message STATIC Message.h Message.cpp) **：生成必要的构建指令，将指定
的源码编译到库中。 

add_library 的第**一个参数是目标名**。整个 CMakeLists.txt 中，可使用相同的名称来引用库。

生成的库的实际名称将由 CMake 通过在前面添加前缀 lib 和适当的扩展名作为后缀来形成。

生成库是根据第二个参数( **STATIC 或 SHARED** )和操作系统确定的。

-------

**target_link_libraries(hello-world message) **: 将库链接到可执行文件。

此命令还确保 hello-world 可执行文件可以正确地依赖于消息库。

因此，在消息库链接到 hello-world 可执行文件之前，需要完成消息库的构建。

编译成功后，构建目录包含 libmessage.a 一个静态库(在GNU/Linux上)和 hello-world 可执行文件。

#### add_library 其他参数

-------

- **STATIC**：用于创建**静态库**，即编译文件的打包存档，以便在链接其他目标时使用，例如：可执行文件。
- **SHARED**：用于创建**动态库**，即可以动态链接，并在运行时加载的库。可以在 CMakeLists.txt 中使用 add_library(message SHARED Message.h Message.cpp) 从静态库切换到动态共享对象(DSO)。
- **OBJECT**：可将给定 add_library 的列表中的源码编译到目标文件，不将它们归档到静态库中，也不能将它们链接到共享对象中。如果需要**一次性创建静态库和动态库**，那么使用对象库尤其有用。
- **MODULE**：又为 DSO 组。与 SHARED 库不同，它们不链接到项目中的任何目标，不过可以进行动态加载。该参数可以用于构建**运行时插件**。

#### CMake 源代码

------

``` cmake
cmake_minimum_required(VERSION 3.5)

project(hello-world LANGUAGES CXX)

# 创建目标——静态库。库的名称和源码文件名相同，具体代码如下：
add_library(message
	# 生成静态库
	STATIC
		# 包含库文件
		Message.h
		Message.cpp
)

# 生成可执行文件
add_executable(hello-world hello-world.cpp)

# 链接目标库到可执行文件
target_link_libraries(hello-world message)
```

