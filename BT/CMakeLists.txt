cmake_minimum_required(VERSION 3.14.0)
project(BT)

# Bring the headers
include_directories(header)

# Add sources manually
#set(SOURCES src/Main.cpp src/BinaryTree.cpp)

# Allow for wildcard additions
file(GLOB SOURCES "src/*.cpp")

add_executable(BT ${SOURCES})
