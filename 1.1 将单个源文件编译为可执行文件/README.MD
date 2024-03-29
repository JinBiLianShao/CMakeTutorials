#### 生成构建器

``` shell
$ mkdir -p build
$ cd build
$ cmake ..
```

>  这里，我们创建了一个目录 build (生成构建器的位置)，进入 build 目录，并通过指定 CMakeLists.txt 的位置(本例中位于父目录中)来调用 CMake。
>
> CMake语言不区分大小写，但是参数区分大小写。
>
> CMake中，C++是默认的编程语言。不过，我们还是建议使用LANGUAGES 选项在 project 命令中显式地声明项目的语言。

可以使用以下命令行来实现相同的效果：

``` shell
$ cmake -H. -Bbuild
# 该命令是跨平台的，使用了-H 和-B 为 CLI 选项。
# -H 表示当前目录中搜索根 CMakeLists.txt 文件。
# -Bbuild 告诉 CMake 在一个名为 build 的目录中生成所有的文件。
```

#### 构建项目

```shell 
# 在 build 文件夹下执行
$ cmake --build .

# Windows 输出如下
$ cmake --build .
用于 .NET Framework 的 Microsoft (R) 生成引擎版本 16.10.2+857e5a733
版权所有(C) Microsoft Corporation。保留所有权利。

  Checking Build System
  Building Custom Rule C:/Users/lw0039780/3D Objects/HelloCMake/CMakeLists.txt
  HelloCMake.cpp
  hello-cmake.vcxproj -> C:\Users\lw0039780\3D Objects\HelloCMake\build\Debug\hello-cmake.exe
  Building Custom Rule C:/Users/lw0039780/3D Objects/HelloCMake/CMakeLists.txt
```

