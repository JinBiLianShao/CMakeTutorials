cmake_minimum_required(VERSION 3.5)

project(hello-world LANGUAGES C CXX)

option(CMAKE_CXX_COMPILER clang++)
message(STATUS "##### 编译器：${CMAKE_CXX_COMPILER_ID}")
message(STATUS "##### 编译器版本：${CMAKE_CXX_COMPILER_VERSION}")

option(USE_LIBRARY OFF)
message(STATUS "##### USE_LIBRARY? ${USE_LIBRARY}")

list(APPEND _sources Message.h Message.cpp)

if (${USE_LIBRARY})
	add_library(message ${_sources})
	add_executable(hello-world hello-world.cpp)
	target_link_libraries(hello-world message)
else()
	add_executable(hello-world hello-world.cpp message)
endif()