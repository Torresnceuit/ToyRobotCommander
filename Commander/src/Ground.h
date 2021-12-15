#pragma once

namespace ToyRobotChallenge
{
	class Position;
	class Ground
	{
		public:
			Ground();
			Ground(const Ground& ground);
			Ground(int width, int height);
			~Ground();

			bool contains(const int x, const int y) const;
			bool contains(const Position& position) const;
			int getWidth() const;
			int getHeight() const;
		
		private:
			int _width;
			int _height;
	};
}
