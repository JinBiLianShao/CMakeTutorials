cmake_minimum_required(VERSION 3.5)

project(diff-platform LANGUAGES CXX)

add_library(progressbar
	SHARED
	ProgressBar.h
	ProgressBar.cpp
)

add_executable(download download.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_definitions(download PUBLIC "IS_LINUX")
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_definitions(download PUBLIC "IS_WINDOWS")
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Drawin")
	target_compile_definitions(download PUBLIC "IS_MACOS")
endif()

target_link_libraries(download progressbar)