#pragma once

#include <string>
#include <memory>
#include <iostream>

namespace ToyRobotChallenge
{
	enum Direction
	{
		NORTH,
		EAST,
		SOUTH,
		WEST
	};
	
	enum Rotation
	{
		LEFT,
		RIGHT
	};

	class Position
	{
		public:
			Position();
			Position(const Position& position);
			Position(const int& x, const int& y, const std::string& direction);
			Position(const int& x, const int& y, const Direction& direction);
			~Position();
			
			Position& operator=(const Position& position);
			
			int getX() const;
			int getY() const;
			Direction getDirection() const;
			void rotate(const Rotation& rotation);
			void move();
			std::string toString() const;
			
		friend std::ostream& operator<<(std::ostream& output, const Position& position);
		
		private:
			Direction getDirectionFromString(const std::string& directionString) const;
		
		private:
			int _x;
			int _y;
			Direction _direction;
			
			static const std::vector<std::string> DIRECTION_MAP;
			static const int NUM_DIRECTIONS;
	};
}
