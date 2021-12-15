#include "MoveCommand.h"

#include "Robot.h"
#include "Position.h"
#include "Ground.h"
namespace ToyRobotChallenge
{
	MoveCommand::MoveCommand(Robot& robot, const Ground& ground)
	: BaseCommand(robot)
	{
		_ground = new Ground(ground);
		run();
	}
	
	MoveCommand::~MoveCommand()
	{
		delete _ground;
	}
	
	void MoveCommand::run()
	{
		Position newPosition(*getRobot()->getPosition());
		newPosition.move();
		if(!_ground->contains(newPosition.getX(), newPosition.getY()))
		{
			std::cout << "Invalid MOVE !!!"<< newPosition << std::endl;
			return;
		}
		getRobot()->setPosition(newPosition);
	}
}

