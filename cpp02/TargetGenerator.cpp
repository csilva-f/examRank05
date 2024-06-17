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

TargetGenerator::~TargetGenerator() 
{
	for (std::map<std::string, ATarget*>::iterator it = this->_targets.begin(); it != this->_targets.end(); ++it)
		delete it->second;
	this->_targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		if (this->_targets.find(target->getType()) == this->_targets.end())
			this->_targets[target->getType()] = target->clone();
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
