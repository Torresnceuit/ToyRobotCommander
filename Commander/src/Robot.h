#pragma once

#include <memory>

namespace ToyRobotChallenge
{
	class Position;
	class Robot
	{
		public:
			Robot();
			Robot(const Robot& robot);
			~Robot();

			bool isPlaced() const;
			void setPosition(const Position& position);
			Position* getPosition() const;
		
		private:
			std::unique_ptr<Position> _position;
	};
}
