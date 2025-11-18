cmake_minimum_required(VERSION 3.13)
project(task)

find_package(GTest REQUIRED)

add_executable(tests
    task.cpp
)

target_link_libraries(tests PRIVATE
    GTest::gtest
    GTest::gtest_main
)

enable_testing()
add_test(NAME tests COMMAND tests)



