cmake_minimum_required(VERSION 3.15)

project(StaticLibrary)

set(SOURCES List1.cpp Node.cpp)
set(HEADERS List1.h Node.h)

add_library(StaticLibrary STATIC ${SOURCES} ${HEADERS})