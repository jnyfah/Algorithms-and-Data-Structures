cmake_minimum_required(VERSION 3.15)
project(ThreadedMap)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES ThreadedMap/*.cpp)

# set(SOURCES
#     ThreadedMap/ConcurrentMap.cpp
#     ThreadedMap/TaskQueue.cpp
#     ThreadedMap/ThreadPool.cpp
# )

add_executable(ThreadedMap ${SOURCES} ThreadedMap/main.cpp)

target_include_directories(ThreadedMap PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ThreadedMap)

target_compile_features(ThreadedMap PRIVATE cxx_std_20)

# enable_testing()
# file(GLOB TEST_SOURCES tests/*.test.cpp)

# add_executable(Tests ${TEST_SOURCES} ${SOURCES})
# target_link_libraries(Tests ThreadedMap)

# add_test(NAME Tests COMMAND Tests)
