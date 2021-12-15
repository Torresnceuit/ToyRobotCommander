#include "BaseCommand.h"
#include "Robot.h"

namespace ToyRobotChallenge
{
	BaseCommand::BaseCommand(Robot& robot)
	: _robot(robot)
	{
	}
	
	BaseCommand::~BaseCommand()
	{
	}
	
	Robot* BaseCommand::getRobot() const
	{
		return &_robot;
	}
}
