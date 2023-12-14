cmake_minimum_required(VERSION 3.22)
project(opencv_pybind11_mre)

find_package(OpenCV)
find_package(pybind11)

pybind11_add_module(example MODULE opencv_pybind11.cpp)

target_link_libraries(example PRIVATE ${OpenCV_LIBS})
target_include_directories(example PRIVATE ${OpenCV_INCLUDE_DIRS})
