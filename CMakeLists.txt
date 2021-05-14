cmake_minimum_required(VERSION 3.16)

add_subdirectory(lib/googletest)

set(CMAKE_CXX_STANDARD 14)

project(hacky CXX)
file(GLOB_RECURSE SRC src/*)
add_library(hacky ${SRC})


enable_testing()

project(hacky_test)
add_executable(hacky_test tests/test.cpp)
target_link_libraries(hacky_test gtest hacky)
target_include_directories(hacky_test PUBLIC lib/googletest/googletest/include src)