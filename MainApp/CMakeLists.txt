cmake_minimum_required(VERSION 3.15)

project(MainApp)

set(SOURCE main.cpp ../StaticLibrary/List1.cpp ../StaticLibrary/List1.h ../StaticLibrary/Node.cpp ../StaticLibrary/Node.h)

add_executable(MainApp ${SOURCE})

# Connecting the library, specify where to get the header file
include_directories("../StaticLibrary")
# And also we specify dependence on static library
target_link_libraries(MainApp StaticLibrary)