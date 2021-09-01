#### 指定编译器

-----

> 目前为止，我们还没有过多考虑如何选择编译器。
>
> CMake可以根据平台和生成器选择编译器，还能将编译器标志设置为默认值。
>
> 然而，我们通常控制编译器的选择。
>
> 在后面的示例中，我们还将考虑构建类型的选择，并展示如何控制编译器标志。

#### 具体实施

-----

> CMake将语言的编译器存储在 CMAKE\_<LANG>\_COMPILER 变量中，其中 <LANG> 是受支持的任何一种语言，
>
> 对于我们的目的是 CXX 、 C 或 Fortran 。用户可以通过以下两种方式之一设置此变量：

1. ``` cmake
   # 使用CLI中的 -D 选项，例如：
   cmake -D CMAKE_CXX_COMPILER=clang++ ..
   ```

2. ``` cmake
   # 通过导出环境变量 CXX (C++编译器)、 CC (C编译器)和 FC (Fortran编译器)。
   # 例如，使用这个命令使用 clang++ 作为 C++ 编译器：
   env CXX=clang++ cmake ..
   ```

#### 编译器选项

- CMAKE_CXX_COMPILER 
- CMAKE_C_COMPILER 
- CMAKE_Fortran_COMPILER

#####实例运行输出结果

``` shell
$ cmake ..

-- Building for: Visual Studio 16 2019
-- Selecting Windows SDK version 10.0.19041.0 to target Windows 10.0.19042.
-- The C compiler identification is MSVC 19.29.30038.1
-- The CXX compiler identification is MSVC 19.29.30038.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30037/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30037/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- ##### Is the C++ compiler loaded? 1 #####
-- ##### The C++ compiler ID is: MSVC #####
-- ##### Is the C++ from GNU?  #####
-- ##### The C++ compiler version is: 19.29.30038.1 #####
-- ##### Is the C compiler loaded? 1 #####
-- ##### The C compiler ID is: MSVC #####
-- ##### Is the C++ from GNU?  #####
-- ##### The C compiler version is: 19.29.30038.1 #####
-- Configuring done
```

