cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 11)
project(lab2.1)

add_subdirectory(src)

add_executable(lab main.c)

target_link_libraries(lab PRIVATE
    numbers
    linear_form
)
