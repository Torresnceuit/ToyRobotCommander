#include "PlaceCommand.h"
#include "Robot.h"
#include "Ground.h"
#include "Position.h"

namespace ToyRobotChallenge
{
	PlaceCommand::PlaceCommand(Robot& robot, const Ground& ground, const Position& position)
	: BaseCommand(robot)
	{
		_ground = new Ground(ground);
		_position = new Position(position);
		run();
	}

	PlaceCommand::~PlaceCommand()
	{
		delete _ground;
		delete _position;
	}

	void PlaceCommand::run()
	{
		if(_ground->contains(*_position))
		{
			getRobot()->setPosition(*_position);
		}
	}
}
