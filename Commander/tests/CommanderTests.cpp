#include "CommanderTests.h"

#include "../src/Robot.h"
#include "../src/Ground.h"
#include "../src/Position.h"

CommanderTests::CommanderTests()
{
	_commander = nullptr;
}

CommanderTests::~CommanderTests()
{}

void CommanderTests::SetUp()
{
	const int HEIGHT = 5, WIDTH = 5;
	Robot robot;
	Ground ground(HEIGHT, WIDTH);
	_commander.reset(new Commander(robot, ground));
	ASSERT_TRUE(_commander != nullptr);
}

void CommanderTests::TearDown()
{
	
}

TEST_F(CommanderTests, testInValidPlaceCommand)
{
	std::string consoleCommand = std::string("place 0,2");
	const bool result = _commander->run(consoleCommand);
	ASSERT_FALSE(result);
}

TEST_F(CommanderTests, testValidPlaceCommand)
{
	std::string consoleCommand = std::string("place 0,2,west");
	const bool result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	ASSERT_TRUE(_commander->getRobot()->isPlaced());
}

TEST_F(CommanderTests, testOutOfGroundPlaceCommand)
{
	// The ground is (5, 5) -> [0..4],[0..4]
	std::string consoleCommand = std::string("place 0,5,west");
	const bool result = _commander->run(consoleCommand);
	ASSERT_TRUE(_commander->getRobot()->isPlaced() == false);
}

TEST_F(CommanderTests, testRotateCommandBeforePlaceRobot)
{
	std::string consoleCommand = std::string("left");
	const bool result = _commander->run(consoleCommand);
	ASSERT_FALSE(result);
}

TEST_F(CommanderTests, testRotateCommand)
{
	// Always have to place robot first
	std::string consoleCommand = std::string("place 0,2,north");
	bool result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	ASSERT_TRUE(_commander->getRobot()->isPlaced());
	
	// Rotate left
	consoleCommand = std::string("left");
	result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	// Expected direction is WEST
	Direction current_direction = _commander->getRobot()->getPosition()->getDirection();
	ASSERT_TRUE(current_direction == Direction::WEST);
	
	// Rotate right
	consoleCommand = std::string("right");
	result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	// Expected direction is NORTH
	current_direction = _commander->getRobot()->getPosition()->getDirection();
	ASSERT_TRUE(current_direction == Direction::NORTH);
	
	// Wrong rotate command
	consoleCommand = std::string("back");
	result = _commander->run(consoleCommand);
	ASSERT_FALSE(result);
	// Expected direction is NORTH
	current_direction = _commander->getRobot()->getPosition()->getDirection();
	ASSERT_TRUE(current_direction == Direction::NORTH);
}

TEST_F(CommanderTests, testMoveCommandBeforePlaceRobot)
{
	std::string consoleCommand = std::string("move");
	const bool result = _commander->run(consoleCommand);
	ASSERT_FALSE(result);
}

TEST_F(CommanderTests, testValidMoveCommand)
{
	// Always have to place robot first
	std::string consoleCommand = std::string("place 0,0,north");
	bool result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	ASSERT_TRUE(_commander->getRobot()->isPlaced());
	
	consoleCommand = std::string("move");
	result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	// Expected current cordinate is (0, 1)
	int x = _commander->getRobot()->getPosition()->getX();
	int y = _commander->getRobot()->getPosition()->getY();
	ASSERT_EQ(x, 0);
	ASSERT_EQ(y, 1);
	
	// Rotate left --> direction = WEST, move will decrease x by 1 and it will be out of ground
	// Expect the command is not executed and cordinate is still (0, 1)
	consoleCommand = std::string("left");
	result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	Direction current_direction = _commander->getRobot()->getPosition()->getDirection();
	ASSERT_TRUE(current_direction == Direction::WEST);
	consoleCommand = std::string("move");
	result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	x = _commander->getRobot()->getPosition()->getX();
	y = _commander->getRobot()->getPosition()->getY();
	ASSERT_EQ(x, 0);
	ASSERT_EQ(y, 1);
}

TEST_F(CommanderTests, testReportCommand)
{
	std::string consoleCommand = std::string("report");
	bool result = _commander->run(consoleCommand);
	// Expected cannot run because no robot placed
	ASSERT_FALSE(result);
	
	consoleCommand = std::string("place 0,3,south");
	result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	ASSERT_TRUE(_commander->getRobot()->isPlaced());
	
	consoleCommand = std::string("report");
	result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	ASSERT_EQ(_commander->getRobot()->getPosition()->toString(), "0,3,SOUTH");
}

TEST_F(CommanderTests, testValidOneLineCommand)
{
	const std::string consoleCommand = std::string("place 0,0,north right right left move report");
	// Expected output: [1,0,EAST]
	const bool result = _commander->run(consoleCommand);
	ASSERT_TRUE(result);
	ASSERT_EQ(_commander->getRobot()->getPosition()->toString(), "1,0,EAST");
}

TEST_F(CommanderTests, testInValidOneLineCommand)
{
	const std::string consoleCommand = std::string("right right left move report");
	// Expected result is false as no robot had been placed
	const bool result = _commander->run(consoleCommand);
	ASSERT_FALSE(result);
}


