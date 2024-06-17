#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string type): _type(type) {}

ATarget::ATarget(const ATarget& other)
{
	*this = other;
}

ATarget	&ATarget::operator=(const ATarget& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

ATarget::~ATarget() {}

std::string const&	ATarget::getType() const
{
	return this->_type;
}

void	ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << this->getType() << " has been " << spell.getEffects() << "!\n";
}
