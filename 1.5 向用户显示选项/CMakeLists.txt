cmake_minimum_required(VERSION 3.5)

project(hello-world LANGUAGES CXX)

option(USE_LIBRARY "Compile sources into a library" OFF)

set(BUILD_SHARED_LIBS OFF)

list(APPEND _sources Message.h Message.cpp)

if (USE_LIBRARY)
	add_library(message ${_sources})
	add_executable(hello-world hello-world.cpp)
	target_link_libraries(hello-world message)
else()
	add_executable(hello-world hello-world.cpp ${_sources})
endif()