cmake_minimum_required(VERSION 3.5)

set (PROJECT_NAME Dynamic_Array)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")
add_executable(${PROJECT_NAME}
    main.cpp
)
