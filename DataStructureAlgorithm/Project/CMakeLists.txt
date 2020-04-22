# 工程配置
cmake_minimum_required(VERSION 2.8)
project( DataStructureAlgorithm )
# set(OpenCV_INCLUDE_DIRS /usr/local/include)
# set(OpenCV_LIBS opencv_core opencv_highgui opencv_imgcodecs)
# 头文件变量的引入
# include_directories( ${OpenCV_INCLUDE_DIRS} )
# 添加执行文件 （名称 源文件）

add_library(loop SHARED src/loop.cpp)

add_executable(main src/main.cpp)

target_link_libraries(main loop)

# add_dependencies(loop)
# 链接库文件
# target_link_libraries( DisplayImage ${OpenCV_LIBS} )

