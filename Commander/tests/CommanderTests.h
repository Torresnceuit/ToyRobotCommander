#pragma once
#include "../src/Commander.h"

#include <gtest/gtest.h>
#include <memory>
using namespace ToyRobotChallenge;

class CommanderTests : public testing::Test
{
public:
	CommanderTests();
	virtual ~CommanderTests() = default;

	void SetUp() override;
	void TearDown() override;
protected:
	std::unique_ptr<Commander> _commander;
};
