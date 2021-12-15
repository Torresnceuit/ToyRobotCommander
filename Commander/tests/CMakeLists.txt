cmake_minimum_required(VERSION 2.8)

project(CommanderTests)

add_executable(
	${PROJECT_NAME}
	CommanderTests.cpp
	CommanderTests.h
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(
	${PROJECT_NAME}
	PUBLIC
		${GTEST_BOTH_LIBRARIES}
		Commander
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
