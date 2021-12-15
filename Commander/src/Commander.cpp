#include "Commander.h"
#include "Robot.h"
#include "Ground.h"
#include "Position.h"
#include "Utils.h"
#include "Commands/BaseCommand.h"
#include "Commands/PlaceCommand.h"
#include "Commands/ReportCommand.h"
#include "Commands/RotateCommand.h"
#include "Commands/MoveCommand.h"

#include <string>
#include <regex>

namespace ToyRobotChallenge
{
	Commander::Commander(const Robot& robot, const Ground& ground)
	{
		_robot.reset(new Robot(robot));
		_ground.reset(new Ground(ground));
	}

	Commander::Commander()
	{
	}
	
	Robot* Commander::getRobot() const
	{
		return _robot.get();
	}
	
	Ground* Commander::getGround() const
	{
		return _ground.get();
	}
	
	bool Commander::canExecute() const
	{
		if(_robot && _robot->isPlaced())
		{
			return true;
		}
		
		std::cout << "Please place robot on the ground first !!!" << std::endl;
		return false;
	}
	
	std::vector<std::string> Commander::parse(const std::string& inputCommands) const
	{
		std::regex sliceInputCommandRegex("PLACE\\s*\\d+\\s*,\\s*\\d+\\s*,\\s*(NORTH|SOUTH|EAST|WEST)"
		                                  "|MOVE"
		                                  "|LEFT"
		                                  "|RIGHT"
		                                  "|REPORT");

		return Utils::regexSearch(inputCommands, sliceInputCommandRegex);
	}
	
	CommandType Commander::getCommandType(const std::string& command) const
	{
		std::regex placeCommandRegex("^PLACE\\s*\\d+\\s*,\\s*\\d+\\s*,\\s*(NORTH|SOUTH|EAST|WEST)$");
		std::regex moveCommandRegex("^MOVE$");
		std::regex leftCommandRegex("^LEFT$");
		std::regex rightCommandRegex("^RIGHT$");
		std::regex reportCommandRegex("^REPORT$");
		
		if(std::regex_match(command.begin(), command.end(), placeCommandRegex))
		{
			return CommandType::PLACE;
		}
		
		if(std::regex_match(command.begin(), command.end(), leftCommandRegex)
		   || std::regex_match(command.begin(), command.end(), rightCommandRegex))
		{
			return CommandType::ROTATE;
		}
		
		if(std::regex_match(command.begin(), command.end(), moveCommandRegex))
		{
			return CommandType::MOVE;
		}
		
		if(std::regex_match(command.begin(), command.end(), reportCommandRegex))
		{
			return CommandType::REPORT;
		}
		
		return CommandType::INVALID;
	}

	bool Commander::run(const std::string& consoleCommands) const
	{
		std::string inputCommands = consoleCommands;
		// Upper the whole string
		Utils::toUpper(inputCommands);
		
		BaseCommand* cmd = nullptr;
		bool ok = false;
		
		std::vector<std::string> commandList = parse(inputCommands);
		
		if(commandList.empty())
		{
			std::cout << "Commands are not allowed !!!" << std::endl;
			return false;
		}
		
		for(auto command : commandList)
		{
			CommandType cmdType = getCommandType(command);
			switch(cmdType)
			{
				case CommandType::PLACE:
				{
					// Split the commands to get the position
					std::vector<std::string> tokens = Utils::regexSplit(command, std::regex("\\s+|\\s*,\\s*"));
					Position placePosition(std::stoi(tokens[1]), std::stoi(tokens[2]), tokens[3]);
		
					cmd = new PlaceCommand(*_robot, *_ground, placePosition);
					ok = true;
					break;
				}
				
				case CommandType::ROTATE:
				{
					if(canExecute())
					{
						cmd = new RotateCommand(*_robot, command);
						ok = true;
					}
					break;
				}
				
				case CommandType::MOVE:
				{
					if(canExecute())
					{
						cmd = new MoveCommand(*_robot, *_ground);
						ok = true;
					}
					break;
				}
				
				case CommandType::REPORT:
				{
					if(canExecute())
					{
						cmd = new ReportCommand(*_robot);
						ok = true;
					}
					break;
				}
				
				default: ok = false;
			}
		}

		delete cmd;
		return ok;
	}
}
