#### 实现效果

------

1. 将 Message.hpp 和 Message.cpp 构建成一个库(静态或动态)，然后将生成库链接到 hello-
world 可执行文件中。
2. 将 Message.hpp ， Message.cpp 和 hello-world.cpp 构建成一个可执行文件，但不生成任
何一个库。

#### 实现方法

------

1. ```cmake
   # 首先，定义最低CMake版本、项目名称和支持的语言：
   cmake_minimum_required(VERSION 3.5)
   
   project(hello-world LANGUAGES CXX)
   ```

2. ``` cmake
   # 我们引入了一个新变量 USE_LIBRARY ，这是一个逻辑变量，值为 OFF 。我们还打印了它的值：
   set(USE_LIBRARY OFF)
   message(STATUS "Compile sources into a library? ${USE_LIBRARY}")
   ```

3. ``` cmake
   # CMake中定义 BUILD_SHARED_LIBS 全局变量，并设置为 OFF 。调用 add_library 并省略第二个参数，将构建一个静态库
   set(BUILD_SHARED_LIBS OFF)
   ```

4. ``` cmake
   # 然后，引入一个变量 _sources，包含所有源文件和头文件：
   list(APPEND _sources Message.h Message.cpp)
   ```

5.  ``` cmake
   # 然后，引入一个基于 USE_LIBRARY 值的 if-else 语句。如果逻辑为真，则 Message.hpp 和 Message.cpp 将打包成一个库：
   if (USE_LIBRARY)
   	add_library(message ${_source})
   	add_executable(hello-world hello-world.cpp)
   	target_link_libraries(hello-world message)
   else()
   	add_executable(hello-world hello-world.cpp ${_sources})
   endif()
    ```

#### 工作原理

------

> 我们介绍了两个变量： USE_LIBRARY 和 BUILD_SHARED_LIBS 。这两个变量都设置为 OFF 。
>
> 如CMake语言文档中描述，逻辑真或假可以用多种方式表示：
> 如果将逻辑变量设置为以下任意一种： 1 、 ON 、 YES 、 true 、 Y 或非零数，则逻辑变量为 true 。
> 如果将逻辑变量设置为以下任意一种： 0 、 OFF 、 NO 、 false 、 N 、 IGNORE、
> NOTFOUND 、空字符串，或者以 -NOTFOUND 为后缀，则逻辑变量为 false 。
> USE_LIBRARY 变量将在第一个和第二个行为之间切换。 BUILD_SHARED_LIBS 是CMake的一个全局标志。因为CMake内部要查询 BUILD_SHARED_LIBS 全局变量，所以 add_library 命令可以在不传递 STATIC/SHARED/OBJECT 参数的情况下调用；如果为 false 或未定义，将生成一个静态库。
>
> 这个例子说明，可以引入条件来控制CMake中的执行流。但是，当前的设置不允许从外部切换，不需要
> 手动修改 CMakeLists.txt 。原则上，我们希望能够向用户开放所有设置，这样就可以在不修改构建
> 代码的情况下调整配置，稍后将展示如何做到这一点。