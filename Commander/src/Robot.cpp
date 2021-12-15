#include "Robot.h"
#include "Position.h"

namespace ToyRobotChallenge
{
	Robot::Robot()
	{
		_position = nullptr;
	}

	Robot::Robot(const Robot& robot)
	{
		_position.reset(robot.getPosition());
	}

	Robot::~Robot()
	{
	}

	bool Robot::isPlaced() const
	{
		return _position != nullptr;
	}

	void Robot::setPosition(const Position& position)
	{
		_position.reset(new Position(position));
	}

	Position* Robot::getPosition() const
	{
		return _position.get();
	}
}
