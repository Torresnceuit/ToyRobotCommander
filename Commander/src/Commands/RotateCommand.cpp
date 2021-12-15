#include "RotateCommand.h"
#include "Robot.h"

namespace ToyRobotChallenge
{
	RotateCommand::RotateCommand(Robot& robot, const std::string& rotationString)
	: BaseCommand(robot)
	{
		_rotation = getRotationFromString(rotationString);
		run();
	}
	
	RotateCommand::~RotateCommand()
	{
	}
	
	void RotateCommand::run()
	{		
		getRobot()->getPosition()->rotate(_rotation);
	}
	
	Rotation RotateCommand::getRotationFromString(const std::string& rotationString) const
	{
		if(rotationString == std::string("LEFT")) return Rotation::LEFT;
		return Rotation::RIGHT;
	}
}
