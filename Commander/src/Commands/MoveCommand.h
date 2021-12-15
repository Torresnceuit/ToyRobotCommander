#pragma once
#include "BaseCommand.h"

namespace ToyRobotChallenge
{
	class Robot;
	class Ground;
	class MoveCommand : public BaseCommand
	{
		public:
			explicit MoveCommand(Robot& robot, const Ground& ground);
			virtual ~MoveCommand();
			virtual void run() override;

		private:
			Ground* _ground;
	};
}
