cmake_minimum_required (VERSION 2.8.11)
project (todo)

add_subdirectory(uforia)
add_executable(todo main.cpp)

target_link_libraries(todo uforia)
