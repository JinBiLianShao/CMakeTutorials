#### 切换构建类型

-----

> CMake可以配置构建类型，例如：Debug、Release等。配置时，可以为Debug或Release构建设置相关的选项或属性，
> 例如：编译器和链接器标志。控制生成构建系统使用的配置变量是CMAKE_BUILD_TYPE。该变量默认为空，CMake识别的值为:
> Debug：           	用于在没有优化的情况下，使用带有调试符号构建库或可执行文件。
> Release：         	用于构建的优化的库或可执行文件，不包含调试符号。
> RelWithDebInfo：用于构建较少的优化库或可执行文件，包含调试符号。
> MinSizeRel：      用于不增加目标代码大小的优化方式，来构建库或可执行文件。

#### 具体实施

------

1. 首先，定义最低CMake版本、项目名称和支持的语言：

``` cmake
cmake_minimum_required(VERSION 3.5)
project(hello-world LANGUAGES CXX)
```

2. 然后，设置一个默认的构建类型(本例中是 Release )，并打印一条消息。要注意的是，该变量被设置为缓存变量，可以通过缓存进行编辑：

``` cmake
if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
message(STATUS "##### Build type is: ${CMAKE_BUILD_TYPE}")
```

3. 打印出CMake设置的相应编译标志：

``` cmake
message(STATUS "##### C flags, Debug: 	${CMAKE_C_FLAGES_DEBUG}")
message(STATUS "##### C flags, Release: ${CMAKE_C_FLAGES_RELEASE}")
message(STATUS "##### C flags, Release: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "##### C flags, minimal: ${CMAKE_C_FLAGS_MINISIZEREL}")
message(STATUS "##### C++ flags, Debug:	${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "##### C++ flags, Release:	${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "##### C++ flags, Release:	${CMAKE_CXX_FELWITHDEBINFO}")
message(STATUS "##### C++ flags, Minimal:	${CMAKE_CXX_FLAGS_MINISIZEREL}")
```

4. 验证配置输出

``` shell
$ mkdir build
$ cd build
$ cmake ..

-- The CXX compiler identification is GNU 10.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- ##### Build type is:                                        Release
-- ##### C flags, Debug configuration:
-- ##### C flags, Release configuration:
-- ##### C flags, Release configuration with Debug info:
-- ##### C flags, minimal Release configuration:
-- ##### C++ flags, Debug configuration:                       -g
-- ##### C++ flags, Release configuration:                     -O3 -DNDEBUG
-- ##### C++ flags, Release configuration with Debug info:     -O2 -g -DNDEBUG
-- ##### C++ flags, minimal Release configuration:             -Os -DNDEBUG
-- Configuring done
-- Generating done
-- Build files have been written to: /d/Databases/Desktop/cmake/build

# 构建
$ cmake --build .

[ 33%] Building CXX object CMakeFiles/hello-world.dir/hello-world.cpp.o
[ 66%] Building CXX object CMakeFiles/hello-world.dir/Message.cpp.o
[100%] Linking CXX executable hello-world.exe
[100%] Built target hello-world

$ ls

CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake  hello-world.exe
```

5. 切换构建类型

``` shell
$ cmake -D CMAKE_BUILD_TYPE=Debug ..

-- The CXX compiler identification is GNU 10.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- ##### Build type is:                                        Debug
-- ##### C flags, Debug configuration:
-- ##### C flags, Release configuration:
-- ##### C flags, Release configuration with Debug info:
-- ##### C flags, minimal Release configuration:
-- ##### C++ flags, Debug configuration:                       -g
-- ##### C++ flags, Release configuration:                     -O3 -DNDEBUG
-- ##### C++ flags, Release configuration with Debug info:     -O2 -g -DNDEBUG
-- ##### C++ flags, minimal Release configuration:             -Os -DNDEBUG
-- Configuring done
-- Generating done
-- Build files have been written to: /d/Databases/Desktop/cmake/build

$ cmake --build .

[ 33%] Building CXX object CMakeFiles/hello-world.dir/hello-world.cpp.o
[ 66%] Building CXX object CMakeFiles/hello-world.dir/Message.cpp.o
[100%] Linking CXX executable hello-world.exe
[100%] Built target hello-world

$ ls

CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake  hello-world.exe
```

6. 多参数构建

``` shell
# 同时构建 Release 和 静态库
$ cmake -D CMAKE_BUILD_TYPE=Release -D USE_LIBRARY=ON ..

-- The CXX compiler identification is GNU 10.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- ##### Build type is:                                        Release
-- ##### C flags, Debug configuration:
-- ##### C flags, Release configuration:
-- ##### C flags, Release configuration with Debug info:
-- ##### C flags, minimal Release configuration:
-- ##### C++ flags, Debug configuration:                       -g
-- ##### C++ flags, Release configuration:                     -O3 -DNDEBUG
-- ##### C++ flags, Release configuration with Debug info:     -O2 -g -DNDEBUG
-- ##### C++ flags, minimal Release configuration:             -Os -DNDEBUG
-- Configuring done
-- Generating done
-- Build files have been written to: /d/Databases/Desktop/cmake/build

$ cmake --build .

[ 25%] Building CXX object CMakeFiles/message.dir/Message.cpp.o
[ 50%] Linking CXX static library libmessage.a
[ 50%] Built target message
[ 75%] Building CXX object CMakeFiles/hello-world.dir/hello-world.cpp.o
[100%] Linking CXX executable hello-world.exe
[100%] Built target hello-world

# 编译出 libmessage.a
$ ls

CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake  hello-world.exe  libmessage.a
```



#### 工作原理

----

我们演示了如何设置默认构建类型，以及如何(从命令行)覆盖它。这样，就可以控制项目，是使用优化，还是关闭优化启用调试。

我们还看到了不同配置使用了哪些标志，这主要取决于选择的编译器。

需要在运行CMake时显式地打印标志，也可以仔细阅读运行`CMake --system-information`的输出，以了解当前平台、默认编译器和语言的默认组合是什么。
