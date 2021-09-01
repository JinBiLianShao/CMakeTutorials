#### 设置编译器选项

---

前面的示例展示了如何探测 CMake，从而获得关于编译器的信息，以及如何切换项目中的编译器。后一个任务是控制项目的编译器标志。CMake为调整或扩展编译器标志提供了很大的灵活性，您可以选择下面两种方法:
		CMake 将编译选项视为目标属性。因此，可以根据每个目标设置编译选项，而不需要覆盖 CMake 默认值。
		可以使用 -D CLI 标志直接修改 CMAKE\_<LANG>\_FLAGS\_<CONFIG> 变量。这将影响项目中的所有目标，并覆盖或扩展 CMake 默认值。

#### 具体实施

----

1. 设置CMake的最低版本:

   ``` cmake
   cmake_minimum_required(VERSION 3.5)
   ```

2. 声明项目名称和语言

   ``` cmake
   project(hello-cmake LANGUAGES CXX)
   ```

3. 然后，打印当前编译器标志。CMake将对所有C++目标使用这些

   ``` cmake
   message(STATUS "C++ compiler flags is: 			${CMAKE_CXX_FLAGS}")
   ```

4. 为目标准备了标志列表，其中一些将无法在Windows上使用

   ``` cmake
   list(APPEND flags "-fPIC" "-Wall")
   
   if (NOT WIN32)
   	list(APPEND flags "-Wextra" "-Wpedantic")
   endif()
   ```

5. 添加了一个新的目标—— message 库，并列出它的源依赖关系

   ``` cmake
   add_library(message 
   	STATIC
   	Message.h
   	Message.cpp
   )
   ```

6. 为这个库目标设置了编译选项

   ``` cmake
   target_compile_options(message
   	PRIVATE
   	${flags}
   )
   ```

7. 然后，将生成 hello-cmake 可执行文件作为一个目标

   ``` cmake
   add_executable(hello-cmake hello-cmake.cpp)
   ```

8. 还为可执行目标设置了编译选项

   ``` cmake
   target_compile_options(hello-cmake
   	PRIVATE
   	"-fPIC"
   )
   ```

9. 最后，将可执行文件链接到 message 库

   ``` cmake
   target_link_libraries(hello-cmake message)
   ```

   

