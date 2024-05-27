#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
private:
	TargetGenerator(const TargetGenerator& other);
	TargetGenerator	&operator=(const TargetGenerator& other);
	std::map<std::string, ATarget*>	_targets;

public:
	TargetGenerator();
	~TargetGenerator();

	void		learnTargetType(ATarget* target);
	void		forgetTargetType(std::string const& type);
	ATarget*	createTarget(std::string const& type);
};
