cmake_minimum_required(VERSION 3.14)

project("cpp-learning" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_FIND_DEBUG_MODE ON)
find_package(GTest CONFIG REQUIRED)
find_package(Folly CONFIG REQUIRED)
find_package(gflags CONFIG REQUIRED)
# get_target_property(GTEST_INCLUDES GTest::gtest INTERFACE_INCLUDE_DIRECTORIES)
# message(STATUS "GTest include dirs (from target): ${GTEST_INCLUDES}")

add_executable(hello src/hello.cpp)

add_executable(test test/main.cpp
    test/t_folly/test_future.cpp
    test/t_folly/test_poly.cpp
)
target_link_libraries(test PRIVATE 
    GTest::gtest
    Folly::folly
)
