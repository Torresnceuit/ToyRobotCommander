#include "Utils.h"
#include <string>

namespace Utils
{
	std::vector<std::string> regexSplit(const std::string& inputString, const std::regex& regexString)
	{
		std::vector<std::string> result;
		std::sregex_token_iterator iter(inputString.begin(), inputString.end(), regexString, -1);
		std::sregex_token_iterator end;

		while (iter != end)  {
				result.push_back(*iter);
				++iter;
		}

		return result;
	}

	std::vector<std::string> regexSearch(const std::string& inputString, const std::regex& regexString)
	{
		std::smatch matches;
		std::vector<std::string> result;

		std::string::const_iterator searchStart(inputString.cbegin());
		while(std::regex_search(searchStart, inputString.cend(), matches, regexString))
		{
			result.push_back(matches[0]);
			searchStart = matches.suffix().first;
		}

		return result;
	}

	void toUpper(std::string& data)
	{
		std::for_each(data.begin(), data.end(), [](char & c) {
        c = std::toupper(c);
    });
	}
}
