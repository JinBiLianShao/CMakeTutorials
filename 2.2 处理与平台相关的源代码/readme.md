#### 处理与平台相关的源代码

---

​       理想情况下，应该避免依赖于平台的源代码，但是有时我们没有选择，特别是当要求配置和编译不是自己编写的代码时。本示例中，将演示如何使用CMake根据操作系统编译源代码。

#### 具体实施

1. 首先，设置了CMake最低版本、项目名称和支持的语言

   ``` cmake
   cmake_minimum_required(VERSION 3.5)
   project(diff-platform LANGUAGES CXX)
   ```

2. 然后，定义可执行文件及其对应的源文件

   ``` cmake
   add_library(progressbar
   	SHARED
   	ProgressBar.h
   	ProgressBar.cpp
   )
   add_executable(download download.cpp)
   target_link_libraries(download progressbar)
   ```

3. 通过定义以下目标编译定义，让预处理器知道系统名称

   ``` cmake
   if (CMAKE_SYSTEM_NAME STREQUE "Linux")
   	target_compile_definitions(download PUBLIC "IS_LINUX")
   endif()
   if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
   	target_compile_definitions(download PUBLIC "IS_WINDOWS")
   endif()
   if (CMAKE_SYSTEM_NAME STREQUAL "Drawin")
   	target_compile_definitions(download PUBLIC "IS_MACOS")
   endif()
   ```

#### 验证

``` shell
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
$ ./download
# Windows 系统上，将看到来自 Windows 的 Hello。其他操作系统将产生不同的输出。

```

