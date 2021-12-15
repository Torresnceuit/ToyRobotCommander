#include "ReportCommand.h"

#include "Robot.h"
#include "Position.h"
namespace ToyRobotChallenge
{
	ReportCommand::ReportCommand(Robot& robot)
	: BaseCommand(robot)
	{
		run();
	}
	
	ReportCommand::~ReportCommand()
	{
	}
	
	void ReportCommand::run()
	{
		std::cout << *(getRobot()->getPosition());
	}
}
