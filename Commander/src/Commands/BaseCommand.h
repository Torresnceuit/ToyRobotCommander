#pragma once

#include <memory>

namespace ToyRobotChallenge
{
	class Robot;
	class Ground;
	class Position;
	class BaseCommand
	{
		public:
			explicit BaseCommand(Robot& robot);
			virtual ~BaseCommand();
			virtual void run() = 0;
			
			Robot* getRobot() const;
			
		private:
			Robot& _robot;
	};
}
