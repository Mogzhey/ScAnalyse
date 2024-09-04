cmake_minimum_required(VERSION 3.13)
project(ScAnalyse VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# inlude pybind
add_subdirectory(extern/pybind11 extern/bin)

# main executable
add_subdirectory(src bin)

target_link_libraries(ScAnalyse PRIVATE pybind11::embed)
