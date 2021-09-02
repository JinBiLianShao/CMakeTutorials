#### 为 XXX 库使能向量化处

---

#### 如何实施

---

1. 声明一个 C++11 项目

   ``` cmake
   cmake_minimum_required(VERSION 3.5 FATAL_ERROE)
   project(use-library LANGUAGES CXX)
   
   set(CMAKE_CXX_STANDARD 11)
   set(CMAKE_CXX_EXTENSIONS OFF)
   set(CMAKE_CXX_STANDARD_REQUIRED ON)
   ```

2. 使用 ProgressBar 库，我们需要在系统上找到它的头文件

   ``` cmake
   find_package(progressbar 0 REQUIRED CONFIG)
   ```

3. CheckCXXCompilerFlag.cmake 标准模块文件

   ``` cmake 
   include(CheckCXXCompilerFlag)
   ```

4. 检查 -march=native 编译器标志是否工作

   ``` cmake
   check_cxx_compiler_flag("-march=native" _march_native_works)
   ```

5. 另一个选项 -xHost 编译器标志也开启

   ``` cmake
   check_cxx_compiler_flag("-xHost" _xhost_works)
   ```

6. 设置了一个空变量 _CXX_FLAGS ，来保存刚才检查的两个编译器中找到的编译器标志。如果看到 _march_native_works ，我们将 _CXX_FLAGS 设置为 -march=native 。如果看到 _xhost_works ，我们将 _CXX_FLAGS 设置为 -xHost 。

   如果它们都不起作用， _CXX_FLAGS 将为空，并禁用矢量化

   ``` cmake
   set(_CXX_FLAGS)
   if (_march_native_works)
   	message(STATUS "##### Using processor's vector instructions (-march=native compiler flag set)")
   	set(_CXX_FLAGS "-march=native")
   elseif (_xhost_works)
   	message(STATUS "##### Using processor's vector instructions (-xHost compiler
   flag set)")
   	set(_CXX_FLAGS "-xHost")
   else ()
   	message(STATUS "##### No suitable compiler flag found for vectorization")
   endif ()
   ```

   