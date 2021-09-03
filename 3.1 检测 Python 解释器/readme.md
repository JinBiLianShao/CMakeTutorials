#### 检测 Python 解释器

Python是一种非常流行的语言。许多项目用Python编写的工具，从而将主程序和库打包在一起，或者在配置或构建过程中使用Python脚本。这种情况下，确保运行时对Python解释器的依赖也需要得到满足。

本示例将展示如何检测和使用Python解释器。

#### 具体实施

1. 首先，定义CMake最低版本和项目名称。注意，这里不需要任何语言支持

   ``` cmake
   cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
   project(find-py LANGUAGES NONE)
   ```

2. 然后，使用 find_package 命令找到Python解释器

   ``` cmake
   find_package(PythonInterp REQUIRED)
   ```

3. 然后，执行Python命令并捕获它的输出和返回值

   ``` cmake 
   execute_process(
   	COMMAND
   		${PYTHON_EXECUTABLE} "-c" "print(\"hello, CMake!\")"
   	RESULT_VARIABLE _status
   	OUTPUT_VARIABLE _output
   	ERROR_QUIET
   	OUTPUT_STRIP_STAILING_WHITESPACE
   )
   ```

4. 最后，打印Python命令的返回值和输出

   ``` cmake 
   messages(STATUS "##### RESULT_VARIABLE is ${_status}")
   messages(STATUS "##### OUTPUT_VARIABLE is ${_output}")
   ```

5. 验证

   ``` shell
   $ mkdir build && cd build
   $ cmake ..
   -- Found PythonInterp: /usr/bin/python3.6 (found version "3.6.8")
   -- ##### RESULT_VARIABLE is 0
   -- ##### OUTPUT_VARIABLE is hello, CMake!
   -- Configuring done
   -- Generating done
   
   ```

#### 工作原理

- find_package 是用于发现和设置包的CMake模块的命令。这些模块包含CMake命令，用于标识系统
  标准位置中的包。CMake模块文件称为 Find<name>.cmake ，当调用 find_package(<name>) 时，
  模块中的命令将会运行。

- PYTHONINTERP_FOUND：     是否找到解释器

- PYTHON_EXECUTABLE：        Python解释器到可执行文件的路径

- PYTHON_VERSION_STRING：Python解释器的完整版本信息

- PYTHON_VERSION_MAJOR： Python解释器的主要版本号

- PYTHON_VERSION_MINOR ： Python解释器的次要版本号

- PYTHON_VERSION_PATCH：  Python解释器的补丁版本号

- 可以强制CMake，查找特定版本的包。

  例如，要求Python解释器的版本大于或等于 2.7

  find_package(PythonInterp 2.7)

- 可以强制满足依赖关系

  find_package(PythonInterp REQUIRED)

#### 其他

- 软件包没有安装在标准位置时，CMake无法正确定位它们。用户可以使用CLI的 -D 参数传递相应的
  选项，告诉CMake查看特定的位置。Python解释器可以使用以下配置

  ` $ cmake -D PYTHON_EXECUTABLE=/custom/location/python .. `