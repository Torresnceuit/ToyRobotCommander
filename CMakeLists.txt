cmake_minimum_required(VERSION 2.8)

project(ToyRobot)
add_executable(${PROJECT_NAME} "ToyRobot.cpp")
target_link_libraries(${PROJECT_NAME} Commander)
add_subdirectory(Commander)
