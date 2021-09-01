cmake_minimum_required(VERSION 3.5)

project(download LANGUAGES CXX)

set(CXX_STANDARD 14)

add_library(progressbar
	SHARED
	ProgressBar.h
	ProgressBar.cpp
)
message(STATUS "##### add_library progressbar done.")

add_library(printer
	SHARED
	Printer.h
	Printer.cpp
)
message(STATUS "##### add_library printer done.")

add_library(sleep
	SHARED
	Sleep.h
	Sleep.cpp
)
message(STATUS "##### add_library sleep done.")

target_compile_options(progressbar
	PRIVATE
	-O3
)

target_compile_options(sleep
	PRIVATE
	-O3
)

target_compile_options(printer
	PRIVATE
	-O3
)

list(APPEND sources_list
	ProgressBar.h
	ProgressBar.cpp
	Printer.h
	Printer.cpp
	Sleep.h
	Sleep.cpp
)
# 循环这些源文件，将它们的优化级别调到 -O2。
message(STATUS "##### Setting source properties using IN LISTS syntax: ")
foreach(_sources IN LISTS sources_list)
	set_source_files_properties(${_sources} PROPERTIES COMPILE_FLAGS -O2)
	message(STATUS "##### Appending -O2 flag for ${_sources}.")
endforeach()

# 循环并在打印每个源文件的 COMPILE_FLAGS 属性
foreach(_source IN LISTS sources_list)
	get_source_file_property(_flags ${_source} COMPILE_FLAGS)
	message(STATUS "##### Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}.")
endforeach()

add_executable(download download.cpp)

target_link_libraries(download progressbar printer sleep)
