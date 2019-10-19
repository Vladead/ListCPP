cmake_minimum_required(VERSION 3.15)

project(Test)

add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
set(SOURCE_FILES main.cpp List1TestWithFixture.cpp)
add_executable(Test ${SOURCE_FILES})
target_link_libraries(Test gtest)

# Connecting the library, specify where to get the header file
include_directories(../StaticLibrary)
# And also we specify dependence on static library
target_link_libraries(Test StaticLibrary)