#### 向用户显示选项

> 前面的配置中，我们引入了条件句：通过硬编码的方式给定逻辑变量值。不过，这会影响用户修改这些变量。
>
> CMake代码没有向读者传达，该值可以从外部进行修改。推荐在 CMakeLists.txt 中使用 option() 命令，
>
> 以选项的形式显示逻辑开关，用于外部设置，从而切换构建系统的生成行为。
>
> 本节的示例将向您展示，如何使用这个命令。

----

#### 具体实施

1. ``` cmake
   # 用一个选项替换上一个示例的 set(USE_LIBRARY OFF) 命令。该选项将修改 USE_LIBRARY 的值，并设置其默认值为 OFF ：
   option(USE_LIBRARY "Compile sources into a library" OFF)
   ```

2. ``` shell
   # 现在，可以通过CMake的 -D CLI 选项，将信息传递给 CMake 来切换库的行为：
   # -D 开关用于为 CMake 设置任何类型的变量：逻辑变量、路径等等。
   $ mkdir build
   $ cd build
   $ cmake -D USE_LIBRARY=ON ..
   $
   $ cmake --build .
   ```

#### 工作原理

----

> option 可接受三个参数：
> option(<option_variable> "help string" [initial value])
>
> ​	<option_variable> 表示该选项的变量的名称。
> ​	"help string" 记录选项的字符串，在CMake的终端或图形用户界面中可见。
> ​	[initial value] 选项的默认值，可以是 ON 或 OFF 。