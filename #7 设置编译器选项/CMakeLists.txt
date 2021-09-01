# 设置编译器选项

cmake_minimum_required(VERSION 3.5)

project(download LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "##### C++ compiler flags is:    ${CMAKE_CXX_FLAGS}")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "##### Build type is:            ${CMAKE_BUILD_TYPE}")

list(APPEND flags "-lpthread" "-Wall")

if (NOT WIN32)
    list(APPEND flags "-Wextra" "-Wpedantic")
endif()

add_library(printer
    STATIC
    Printer.h
    Printer.cpp
)

add_library(progressbar
    STATIC
    ProgressBar.h
    ProgressBar.cpp
)

add_library(sleep
    STATIC
    Sleep.h
    Sleep.cpp
)

target_compile_options(printer
    PRIVATE
    ${flags}
)

target_compile_options(sleep
    PRIVATE
    ${flags}
)

target_compile_options(progressbar
    PRIVATE
    ${flags}
)

add_executable(download download.cpp)

target_link_libraries(download progressbar printer sleep)
