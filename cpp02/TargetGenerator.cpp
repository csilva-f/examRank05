#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator& other)
{
	*this = other;
}
TargetGenerator	&TargetGenerator::operator=(const TargetGenerator& other)
{
	if (this != &other)
		this->_targets = other._targets;
	return *this;
}

TargetGenerator::~TargetGenerator() {}

void	TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		this->_targets[target->getType()] = target;
}

void	TargetGenerator::forgetTargetType(std::string const& type)
{
	if (this->_targets.find(type) != this->_targets.end())
		this->_targets.erase(this->_targets.find(type));
}

ATarget*	TargetGenerator::createTarget(std::string const& type)
{
	ATarget*	tg = NULL;
	if (this->_targets.find(type) != this->_targets.end())
		tg = this->_targets[type];
	return tg;
}
