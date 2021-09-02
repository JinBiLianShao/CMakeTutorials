cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(qt-example LANGUAGES CXX)
message(STATUS "##### project name is ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Qt5PATH "C:\\Users\\lw0039780\\.software\\Qt\\5.12.9\\mingw73_64")
message(STATUS "##### Qt5PATH is ${Qt5PATH}")

set(CMAKE_PREFIX_PATH ${Qt5PATH})

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

find_package(Qt5 COMPONENTS Core)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
