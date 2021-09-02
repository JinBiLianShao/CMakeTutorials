#### 处理与编译器相关的源代码

---

#### 具体实施

---

1. CMakeLists.txt 文件中，定义了CMake最低版本、项目名称和支持的语言

   ``` cmake
   cmake_minimum_required(VERSION 3.5)
   project(hello-world LANGUAGES CXX)
   ```

2. 然后，定义可执行目标及其对应的源文件

   ``` cmake
   add_executable(hello-world hello-world.cpp)
   ```

3. 通过定义以下目标编译定义，让预处理器了解编译器的名称和供应商

   ``` cmake
   target_compile_definitions(hello-world PUBLIC "COMPILER_NAME=\"${CMAKE_CXX_COMPILER_ID}\"")
   
   if (CMAKE_CXX_COMPILER_ID MATCHES Intel)
   	target_compile_definitions(hello-world PUBLIC "IS_INTEL_CXX_COMPILER")
   endif()
   
   if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
   	target_compile_definitions(hello-world PUBLIC "IS_GNU_CXX_COMPILER")
   endif()
   
   if (CMAKE_CXX_COMPILER_ID MATCHES PGI)
   	target_compile_definitions(hello-world PUBLIC "IS_PGI_CXX_COMPILER")
   endif()
   
   if (CMAKE_CXX_COMPILER_ID MATCHES XL)
   	target_compile_definitions(hello-world PUBLIC "IS_XL_CXX_COMPILER")
   endif()
   ```

#### 验证

---

``` shell
$ mkdir build && cd build
$ cmake ..
-- The CXX compiler identification is GNU 4.8.5
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done

$ cmake build .
[ 50%] Building CXX object CMakeFiles/hello-world.dir/hello-world.cpp.o
[100%] Linking CXX executable hello-world
[100%] Built target hello-world

$ ./hello-world
Hello GNU compiler!
compiler name is GNU
```

#### 工作原理

---

CMakeLists.txt 会在配置时，进行预处理定义，并传递给预处理器。

我们使用 CMAKE_Intel_COMPILER_ID 变量，通过 target_compile_definition 使用构造预处理器进行预处理定义。

通过使用相应的 CMAKE_C_COMPILER_ID 和 CMAKE_CXX_COMPILER_ID 变量，我们可以在 C 或 C++ 中实现。