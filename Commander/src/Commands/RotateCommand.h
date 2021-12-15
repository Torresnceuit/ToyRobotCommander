#pragma once
#include "BaseCommand.h"
#include "Position.h"
namespace ToyRobotChallenge
{
	class Robot;
	class RotateCommand : public BaseCommand
	{
		public:
			explicit RotateCommand(Robot& robot, const std::string& rotationString);
			virtual ~RotateCommand() = default;
			virtual void run() override;

		private:
			Rotation getRotationFromString(const std::string& rotationString) const;

		private:
			Rotation _rotation;
	};
}
