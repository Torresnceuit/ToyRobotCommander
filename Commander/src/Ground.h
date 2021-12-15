#pragma once

namespace ToyRobotChallenge
{	
	class Ground
	{
		public:
			Ground();
			Ground(const Ground& ground);
			Ground(int width, int height);
			~Ground();

			bool contains(const int x, const int y);
			int getWidth() const;
			int getHeight() const;
		
		private:
			int _width;
			int _height;
	};
}
