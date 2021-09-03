cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(find-py LANGUAGES NONE)

find_package(PythonInterp REQUIRED)

execute_process(
	COMMAND
		${PYTHON_EXECUTABLE} "-c" "print(\"hello, CMake!\")"
	RESULT_VARIABLE _status
	OUTPUT_VARIABLE _hello_cmake
	ERROR_QUIET
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "##### RESULT_VARIABLE is ${_status}")
message(STATUS "##### OUTPUT_VARIABLE is ${_hello_cmake}")
