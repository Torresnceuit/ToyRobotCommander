#pragma once

#include <vector>
#include <regex>

namespace Utils
{
	std::vector<std::string> regexSplit(const std::string& inputString, const std::regex& regexString);
	std::vector<std::string> regexSearch(const std::string& inputString, const std::regex& regexString);
	void toUpper(std::string& data);
}
