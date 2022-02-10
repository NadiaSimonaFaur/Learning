cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello VERSION 0.0.1)



add_executable(hello hello_world.cpp src/Figura.cpp src/Dreptunghi.cpp src/Cerc.cpp  src/Controller.cpp)
target_include_directories(hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


