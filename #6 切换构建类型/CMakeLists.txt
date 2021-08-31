cmake_minimum_required(VERSION 3.5)

project(hello-cmake LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

option(ADD_LIBRARY OFF)

list(APPEND _sources Message.h Message.cpp)

message(STATUS "##### Build type is:                                    ${CMAKE_BUILD_TYPE}")
message(STATUS "##### C flags, Debug configuration:                     ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "##### C flags, Release configuration:                   ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "##### C flags, Release configuration with Debug info:   ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "##### C flags, minimal Release configuration:           ${CMAKE_C_FLAGS_MINSIZEREL}")
message(STATUS "##### C++ flags, Debug configuration:                   ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "##### C++ flags, Release configuration:                 ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "##### C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "##### C++ flags, minimal Release configuration:         ${CMAKE_CXX_FLAGS_MINSIZEREL}")

if (ADD_LIBRARY)
    add_library(message ${_sources})
    add_executable(hello-world hello-world.cpp)
    target_link_libraries(hello-world message)
else()
    add_executable(hello-world hello-world.cpp ${_sources})
endif()
