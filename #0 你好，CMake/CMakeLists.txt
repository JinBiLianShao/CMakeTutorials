# 第一行，设置CMake所需的最低版本。如果使用的CMake版本低于该版本，则会发出致命错误：
cmake_minimum_required(VERSION 3.5)

# 第二行，声明了项目的名称(recipe-01)和支持的编程语言(CXX代表C++)：
project(hello-cmake LANGUAGES CXX)

# 指示CMake创建一个新目标：可执行文件hello-world。
# 这个可执行文件是通过编译和链接源文件hello-world.cpp生成的。
# CMake将为编译器使用默认设置，并自动选择生成工具：
add_executable(hello-cmake HelloCMake.cpp HelloCMake.h)