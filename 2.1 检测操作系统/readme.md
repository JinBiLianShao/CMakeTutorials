#### 检测操作系统

---

CMake是一组跨平台工具。不过，了解操作系统(OS)上执行配置或构建步骤也很重要。

从而与操作系统相关的CMake代码，会根据操作系统启用条件编译，或者在可用或必要时使用特定于编译器的扩展。

本示例中，我们将通过一个不需要编译任何源代码的示例，演示如何使用CMake检测操作系统。

为了简单起见，我们只考虑配置过程。

#### 具体实施

---

1. 首先，定义CMake最低版本和项目名称。请注意，语言是 NONE

   ``` cmake
   cmake_minimum_required(VERSION 3.5)
   project(check-os LANGUAGES NONE)
   ```

2. 然后，根据检测到的操作系统信息打印消息

   ``` cmake
   if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
   	message(STATUS "##### Configuring on/for Linux")
   elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
   	message(STATUS "##### Configuring on/for MacOS")
   elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
   	message(STATUS "##### Configuring on/for Windows")
   elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
   	message(STATUS "##### Configuring on/for IBM AIX")
   else()
   	message(STATUS "##### Configuring on/for ${CMAKE_SYSTEM_NAME}")
   endif()
   ```

#### 验证

``` shell
$ mkdir build && cd build
$ cmake ..
-- Building for: Visual Studio 16 2019
-- Selecting Windows SDK version 10.0.19041.0 to target Windows 10.0.19042.
-- ##### Configuring on/for Windows
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/lw0039780/3D Objects/2.1 检测操作系统/build

```

