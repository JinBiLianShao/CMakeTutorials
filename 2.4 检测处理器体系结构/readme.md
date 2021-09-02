#### 检测处理器体系结构

---

19世纪70年代，出现的 64 位整数运算和本世纪初出现的用于个人计算机的 64 位寻址，扩大了内存寻址范围，开发商投入了大量资源来移植为 32 位体系结构硬编码，以支持 64 位寻址。

虽然，避免显式硬编码的方式非常明智，但需要在使用 CMake 配置的代码中适应硬编码限制。

本示例中，我们会来讨论检测主机处理器体系结构的选项。

#### 具体实施

---

1. 首先，定义可执行文件及其源文件依赖关系

   ``` cmake
   cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
   project(check-arch LANGUAGES CXX)
   add_executable(arch-dependent arch-dependent.cpp)
   ```

2. 检查空指针类型的大小。

   CMake 的 CMAKE_SIZEOF_VOID_P 变量会告诉我们 CPU 是 32 位还是 64 位。

   我们通过状态消息让用户知道检测到的大小，并设置预处理器定义

   ``` cmake
   if (CMAKE_SIZEOF_VOID_P EQUAL 8)
   	target_compile_definitions(arch-dependent PUBLIC "IS_64_BIT_ARCH")
   	message(STATUS "##### Target is 64 bits.")
   else()
   	target_compile_definitions(arch-dependent PUBLIC "IS_32_BIT_ARCH")
   	message(STATUS "##### Targer is 32 bits.")
   endif()
   ```

3. 通过定义以下目标编译定义，让预处理器了解主机处理器架构，同时在配置过程中打印状态消息

   ``` cmake
   if (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i386")
   	message(STATUS "##### i386 architecture detected")
   elseif (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
   	message(STATUS "##### i686 architecture detected")
   elseif (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
   	message(STATUS "##### x86_64 architecture detected")
   else()
   	message(STATUS "##### host processor architecture is unknown")
   endif()
   
   targer_compile_definitions(arch-dependent
   	PUBLIC
   	"ARCHITECTURE=${CMAKE_HOST_SYSTEM_PROCESSOR}"
   )
   ```

#### 验证

---

``` shell
$ mkdir build && cd build
$ cmake ..
-- The CXX compiler identification is GNU 8.4.1
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- ##### Target is 64 bits.
-- ##### x86_64 architecture detected
-- Configuring done
-- Generating done

$ cmake --build .
[ 50%] Building CXX object CMakeFiles/arch-dependent.dir/arch-dependent.cpp.o
[100%] Linking CXX executable arch-dependent
[100%] Built target arch-dependent

$ ./arch-dependent
x86_64 architecture.
Compiled on a 64 bit host processor.
```

