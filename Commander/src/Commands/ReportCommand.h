#pragma once
#include "BaseCommand.h"
namespace ToyRobotChallenge
{
	class Robot;
	class ReportCommand : public BaseCommand
	{
		public:
			explicit ReportCommand(Robot& robot);
			virtual ~ReportCommand();
			virtual void run() override;
	};
}
