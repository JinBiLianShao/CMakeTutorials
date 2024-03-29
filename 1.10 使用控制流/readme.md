#### 使用控制流 （Linux 环境下正常）

---

本章前面的示例中，已经使用过 if-else-endif 。

CMake还提供了创建循环的语言工具： foreach endforeach 和 while-endwhile 。两者都可以与 break 结合使用，以便尽早从循环中跳出。

本示例将展示如何使用 foreach ，来循环源文件列表。我们将应用这样的循环，在引入新目标的前提下，来为一组源文件进行优化降级。

#### 具体实施

----

1. 声明最低要求的 CMake 版本，项目名称和语言，并声明了库目标

   ``` cmake
   cmake_minimum_required(VERSION 3.5)
   project(download LIANGUAGES CXX)
   add_library(progressbar
   	SHARED
   	ProgressBar.h
   	ProgressBar.cpp
   )
   add_library(printer
   	SHARED
   	Printer.h
   	Printer.cpp
   )
   add_library(sleep
   	SHARED
   	Sleep.h
   	Sleep.cpp
   )
   ```

2. 使用` -O3 `编译器优化级别编译库，对目标设置一个私有编译器选项

   ``` cmake
   target_compile_options(progressbar
   	PRIVATE
   	-O3
   )
   target_compile_options(Sleep
   	PRIVATE
   	-O3
   )
   target_compile_options(
   	PRIVATE
   	-O3
   )
   ```

3. 然后，生成一个源文件列表，以较低的优化选项进行编译

   ``` cmake
   list(APPEND sources_list
   	ProgressBar.h
   	ProgressBar.cpp
   	Sleep.h
   	Sleep.cpp
   	Printer.h
   	Printer.cpp
   )
   ```

4. 循环这些源文件，将它们的优化级别调到 -O2 。使用它们的源文件属性完成:

   ``` cmake
message(STATUS "##### Setting source properties using IN LISTS syntax: ")
   foreach(_source IN LISTS sources_list)
   	set_source_files_properties($(_source) PROPERTIES COMPILE_FLAGS -O2)
   	message(STATUS "##### Appending -O2 flag for ${_source}")
   endforeach()
   ```
   
5. 为了确保设置属性，再次循环并在打印每个源文件的 COMPILE_FLAGS 属性

   ``` cmake 
   foreach(_source IN LISTS sources_list)
   	get_source_files_property(_flags ${_source} COMPILE_FLAGS)
   	message(STATUS "##### Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
   endforeach()
   ```
   
6. 最后，添加 download 可执行目标，并将 progressbar、printer、sleep 库连接上去

   ``` cmake
   add_executable(download download.cpp)
   target_link_libraries(download progressbar printer sleep)
   ```

#### 工作原理

---

foreach-endforeach 语法可用于在变量列表上，表示重复特定任务。

本示例中，使用它来操作、设置和获取项目中特定文件的编译器标志。CMake代码片段中引入了另外两个新命令:

- set_source_files_properties(file PROPERTIES property value) ，它将属性设置为给定文件的传递值。

  与目标非常相似，文件在CMake中也有属性，允许对构建系统进行非常细粒度的控制。

- get_source_file_property(VAR file property) ，检索给定文件所需属性的值，并将其存储在 CMake VAR 变量中。

  ----

- CMake中，列表是用分号分隔的字符串组。列表可以由 list 或 set 命令创建。

  例如， set(var a b c d e) 和 list(APPEND a b c d e) 都创建了列表 a;b;c;d;e 。