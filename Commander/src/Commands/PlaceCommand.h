#pragma once
#include "BaseCommand.h"

namespace ToyRobotChallenge
{
	class Robot;
	class Ground;
	class Position;
	class PlaceCommand : public BaseCommand
	{
		public:
			explicit PlaceCommand(Robot& robot, const Ground& ground, const Position& position);
			virtual ~PlaceCommand();
			virtual void run() override;

		private:
			Ground* _ground;
			Position* _position;
	};
}
