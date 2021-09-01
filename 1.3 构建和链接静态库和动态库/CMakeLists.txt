cmake_minimum_required(VERSION 3.5)

project(hello-world LANGUAGES CXX)

# 创建目标——静态库。库的名称和源码文件名相同，具体代码如下：
add_library(message
	# 生成静态库
	STATIC
		# 包含库文件
		Message.h
		Message.cpp
)

# 生成可执行文件
add_executable(hello-world hello-world.cpp)

# 链接目标库到可执行文件
target_link_libraries(hello-world message)
