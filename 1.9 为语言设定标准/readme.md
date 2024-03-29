#### 设置编译器选项

---

编程语言有不同的标准，即提供改进的语言版本。启用新标准是通过设置适当的编译器标志来实现的。
前面的示例中，我们已经展示了如何为每个目标或全局进行配置。

3.1版本中，CMake引入了一个独立于平台和编译器的机制，用于为 C++ 和 C 设置语言标准：为目标设置 <LANG>_STANDARD 属性。

#### 具体实施

----

1. 声明最低要求的 CMake 版本，项目名称和语言

   ``` cmake
   cmake_minimum_required(VERSION 3.5)
   project(download LIANGUAGES CXX)
   ```

2. 要求在 Windows 上导出所有库符号

   ``` cmake
   ser(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
   ```

3. 需要为库添加一个目标，这将编译源代码为一个动态库

   ``` cmake
   add_library(progressbar
   	SHARED
   	ProgressBar.h
   	ProgressBar.cpp
   )
   ```

4. 现在，为目标设置了 CXX_STANDARD 、 CXX_EXTENSIONS 和 CXX_STANDARD_REQUIRED 属性。

   还设置了 position_independent ent_code 属性，以避免在使用一些编译器构建 DSO 时出现问题

   ``` cmake
   set_target_properties(
   	PROPERTIES
   	CXX_STANDARD 14
   	CXX_EXTENSIONS OFF
   	CXX_STANDARD_REQUIRED ON
   	POSITION_INDEPENDENT_CODE 1
   )
   ```

5. 然后，为 download 的可执行文件添加一个新目标，并设置它的属性

   ``` cmake 
   add_executable(download download.cpp)
   set_target_properties(progressbar
   	PROPERTIES
   	CXX_STANDARD 14
   	CXX_EXTENSIONS OFF
   	CXX_STANDARD_REQUIRED ON
   )
   ```

6. 最后，将可执行文件链接到库

   ``` cmake
   target_link_libraries(download progressbar)
   ```

#### 工作原理

- CXX_STANDARD 会设置我们想要的标准。

- CXX_EXTENSIONS 告诉 CMake，只启用 ISO C++ 标准的编译器标志，而不使用特定编译器的扩展。

- CXX_STANDARD_REQUIRED 指定所选标准的版本。如果这个版本不可用，CMake将停止配置并出现错误。

  当这个属性被设置为 OFF 时，CMake将寻找下一个标准的最新版本，直到一个合适的标志。

  这意味着，首先查找 C++14 ，然后是 C++11 ，然后是 C++98 。
