cmake_minimum_required(VERSION 3.11)
project(Clion)

set(CMAKE_CXX_STANDARD 14)

# 添加头文件目录
include_directories(./include /usr/include)

# 添加链接库的路径
link_directories(/usr/lib/x86_64-linux-gnu/ )
# 添加链接库
link_libraries(libpthread.so)
# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

#add_library(libpthread.so)

#add_subdirectory(./src)

add_executable(rename src/main.cpp src/joseph.cpp src/cyclelist.cpp include/cyclelist.h src/kmp.cpp include/kmp.h)