#include "BaseCommand.h"
#include "Robot.h"

namespace ToyRobotChallenge
{
	BaseCommand::BaseCommand(Robot& robot)
	: _robot(robot)
	{
	}

	Robot* BaseCommand::getRobot() const
	{
		return &_robot;
	}
}
