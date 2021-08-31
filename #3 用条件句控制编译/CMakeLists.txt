cmake_minimum_required(VERSION 3.5)

project(hello-world LANGUAGES CXX)

# 引入了一个新变量 USE_LIBRARY ，这是一个逻辑变量，值为 OFF。
set(USE_LIBRARY OFF)
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

# CMake中定义 BUILD_SHARED_LIBS 全局变量，并设置为 OFF。
# 调用 add_library 并省略第二个参数，将构建一个静态库
set(BUILD_SHARED_LIBS OFF)

# 然后，引入一个变量 _sources ，包括 Message.h 和 Message.cpp ：
list(APPEND _sources Message.h Message.cpp)

# 然后，引入一个基于 USE_LIBRARY 值的 if-else 语句。
# 如果逻辑为真，则 Message.hpp 和 Message.cpp 将打包成一个库：
if (USE_LIBRARY)
	add_library(message ${_sources})
	add_executable(hello-world hello-world.cpp)
	target_link_libraries(hello-world message)
else()
	add_executable(hello-world hello-world.cpp ${_sources})
endif()
