
project(IPOPTTEST)

cmake_minimum_required (VERSION 3.5)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(sources src/main.cpp)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(IPOPTTEST ${sources})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
target_link_libraries(IPOPTTEST ipopt python2.7)
else()
target_link_libraries(IPOPTTEST ipopt python)
endif()