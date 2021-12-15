cmake_minimum_required(VERSION 2.8)

project(Commander)

set(COMMANDER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(
	COMMANDER_FILES
	${COMMANDER_SOURCE_DIR}/Commander.cpp
	${COMMANDER_SOURCE_DIR}/Commander.h
	${COMMANDER_SOURCE_DIR}/Ground.cpp
	${COMMANDER_SOURCE_DIR}/Ground.h
	${COMMANDER_SOURCE_DIR}/Robot.cpp
	${COMMANDER_SOURCE_DIR}/Robot.h
	${COMMANDER_SOURCE_DIR}/Position.cpp
	${COMMANDER_SOURCE_DIR}/Position.h
	${COMMANDER_SOURCE_DIR}/Utils.cpp
	${COMMANDER_SOURCE_DIR}/Utils.h
	${COMMANDER_SOURCE_DIR}/Commands/BaseCommand.cpp
	${COMMANDER_SOURCE_DIR}/Commands/BaseCommand.h
	${COMMANDER_SOURCE_DIR}/Commands/PlaceCommand.cpp
	${COMMANDER_SOURCE_DIR}/Commands/PlaceCommand.h
	${COMMANDER_SOURCE_DIR}/Commands/ReportCommand.cpp
	${COMMANDER_SOURCE_DIR}/Commands/ReportCommand.h
	${COMMANDER_SOURCE_DIR}/Commands/RotateCommand.cpp
	${COMMANDER_SOURCE_DIR}/Commands/RotateCommand.h
	${COMMANDER_SOURCE_DIR}/Commands/MoveCommand.cpp
	${COMMANDER_SOURCE_DIR}/Commands/MoveCommand.h
)

add_library(${PROJECT_NAME} ${COMMANDER_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
		${COMMANDER_SOURCE_DIR}
)

add_subdirectory(tests)
