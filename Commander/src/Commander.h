#pragma once

#include <memory>

namespace ToyRobotChallenge
{
	enum class CommandType
	{
		PLACE,
		ROTATE,
		MOVE,
		REPORT,
		INVALID
	};

	class Robot;
	class Ground;
	class Position;
	class Commander
	{
		public:
			explicit Commander(const Robot& robot, const Ground& ground);
			Commander();
			~Commander() = default;
			
			bool run(const std::string& consoleCommands) const;
			Robot* getRobot() const;
			Ground* getGround() const;
			
		private:
			bool canExecute() const;
			std::vector<std::string> parse(const std::string& inputCommands) const;
			CommandType getCommandType(const std::string& command) const;
		
		private:
			std::unique_ptr<Robot> _robot;
			std::unique_ptr<Ground> _ground;
	};
}
