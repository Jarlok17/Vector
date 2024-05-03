cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME Qt)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

project(${PROJECT_NAME})

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

file(GLOB srcs
	"${PROJECT_SOURCE_DIR}/src/*.*"
)

add_executable(${PROJECT_NAME} ${srcs})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui)
