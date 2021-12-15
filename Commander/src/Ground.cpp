#include "Ground.h"
#include "Position.h"
namespace ToyRobotChallenge
{
	Ground::Ground()
	{
		_width = 0;
		_height = 0;
	}
	
	Ground::Ground(const Ground& ground)
	{
		_width = ground.getWidth();
		_height = ground.getHeight();
	}

	Ground::Ground(int width, int height)
	{
		_width = width;
		_height = height;
	}
	
	int Ground::getWidth() const
	{
		return  _width;
	}
	
	int Ground::getHeight() const
	{
		return _height;
	}

	Ground::~Ground()
	{
	}

	bool Ground::contains(const int x, const int y) const
	{
		return (x < 0 || x >= _width) || (y < 0 || y >= _height) ? false : true;
	}
	
	bool Ground::contains(const Position& position) const
	{
		return contains(position.getX(),  position.getY());
	}
}
