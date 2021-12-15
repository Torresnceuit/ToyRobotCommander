#include "Position.h"
#include <vector>

namespace ToyRobotChallenge
{
	const std::vector<std::string> Position::DIRECTION_MAP {"NORTH","EAST","SOUTH","WEST"};
	const int Position::NUM_DIRECTIONS = 4;
	Position::Position()
	{
		_x = 0;
		_y = 0;
		_direction = Direction::NORTH;
	}

	Position::Position(const Position& position)
	{
		_x = position._x;
		_y = position._y;
		_direction = position._direction;
	}

	Position::Position(const int& x, const int& y, const std::string& directionString)
	{
		_x = x;
		_y = y;
		_direction = getDirectionFromString(directionString);
	}

	Position::Position(const int& x, const int& y, const Direction& direction)
	{
		_x = x;
		_y = y;
		_direction = direction;
	}

	Position::~Position()
	{

	}

	Position& Position::operator=(const Position& position)
	{
		if(this == &position)
		{
			return *this;
		}

		_x = position._x;
		_y = position._y;
		_direction = position._direction;
		return *this;
	}

	int Position::getX() const
	{
		return _x;
	}

	int Position::getY() const
	{
		return _y;
	}

	Direction Position::getDirection() const
	{
		return _direction;
	}

	std::ostream& operator<<(std::ostream& output, const Position& position)
	{ 
		 output << position._x
		        << ","
		        << position._y
		        << ","
		        << position.DIRECTION_MAP[static_cast<int>(position._direction)]
		        << std::endl;
		 return output;            
	}

	Direction Position::getDirectionFromString(const std::string& directionString) const
	{
		if(directionString == std::string("NORTH")) return Direction::NORTH;
		if(directionString == std::string("EAST")) return Direction::EAST;
		if(directionString == std::string("SOUTH")) return Direction::SOUTH;
		return Direction::WEST;
	}

	void Position::rotate(const Rotation& rotation)
	{
		if(rotation == Rotation::LEFT)
		{
			auto directionValue = static_cast<int>(_direction);
			directionValue = (directionValue + NUM_DIRECTIONS - 1) % NUM_DIRECTIONS;
			_direction = static_cast<Direction>(directionValue);
			return;
		}

		if(rotation == Rotation::RIGHT)
		{
			auto directionValue = static_cast<int>(_direction);
			directionValue = (directionValue + 1) % NUM_DIRECTIONS;
			_direction = static_cast<Direction>(directionValue);
			return;
		}

		std::cout << "Cannot rotate the robot" << std::endl;
	}

	void Position::move()
	{
		switch(_direction)
		{
			case Direction::NORTH:
				_y += 1;
				break;
			case Direction::SOUTH:
				_y -= 1;
				break;
			case Direction::EAST:
				_x += 1;
				break;
			case Direction::WEST:
				_x -= 1;
				break;
			default:
				std::cout << "Cannot move the robot";
		}
	}

	std::string Position::toString() const
	{
		return std::string(std::to_string(_x) + "," + std::to_string(_y) + "," + DIRECTION_MAP[static_cast<int>(_direction)]);
	}
}
