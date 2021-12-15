#pragma once
#include "BaseCommand.h"
namespace ToyRobotChallenge
{
	class Robot;
	class ReportCommand : public BaseCommand
	{
		public:
			explicit ReportCommand(Robot& robot);
			virtual ~ReportCommand() = default;
			virtual void run() override;
	};
}
