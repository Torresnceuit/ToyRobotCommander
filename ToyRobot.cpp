#include <iostream>

#include "Commander.h"
#include "Robot.h"
#include "Ground.h"

using namespace ToyRobotChallenge;
const int GROUND_WIDTH = 5;
const int GROUND_HEIGHT = 5;

int main()
{
	try
	{
		Robot robot;
		Ground ground(GROUND_WIDTH, GROUND_HEIGHT);
		Commander commander(robot, ground);
		std::cout << "Waiting for commands .... Type empty to stop" << std::endl;

		while(true)
		{
				std::string inputCommands;
				std::getline(std::cin, inputCommands);

				if(inputCommands.empty())
				{
						break;
				}

				commander.run(inputCommands);
		}
	}
	catch(...)
	{
		std::cout << "Cannot read the inputs" << std::endl;
		return 1;
	}

	return 0;
}
