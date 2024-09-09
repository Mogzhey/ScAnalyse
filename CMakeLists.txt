cmake_minimum_required(VERSION 3.13)
project(ScAnalyse VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# inlude pybind
add_subdirectory(extern/pybind11 extern/bin)

# include Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts)
qt_standard_project_setup()

# build executable
add_subdirectory(src bin)

# link against pybind11 and Qt
target_link_libraries(ScAnalyse PRIVATE
	pybind11::embed
	Qt6::Core
	Qt6::Gui
	Qt6::Widgets
	Qt6::Charts
)