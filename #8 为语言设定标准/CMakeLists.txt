cmake_minimum_required(VERSION 3.5)

project(download LANGUAGES CXX)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
message(STATUS "##### CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS  -->  ${CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS}")

add_library(progressbar
	SHARED
	ProgressBar.h
	ProgressBar.cpp
)

set_target_properties(
	PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
	POSITION_INDEPENDENT_CODE 1
)

add_executable(download download.cpp)

set_target_properties(
	PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
)

target_link_libraries(download progressbar)