#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ATarget.hpp"
#include "ATarget.hpp"

class TargetGenerator {
private:
	std::map<std::string, ATarget*>	_targets;

	TargetGenerator(TargetGenerator const &src);
	TargetGenerator &operator=(TargetGenerator const &src);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const &targettype);
	ATarget* createTarget(std::string const &tagettype);
};

