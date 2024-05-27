#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string name, std::string effects): _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell& other)
{
	*this = other;
}

ASpell	&ASpell::operator=(const ASpell& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return *this;
}

ASpell::~ASpell() {}

std::string	ASpell::getName() const
{
	return this->_name;
}

std::string	ASpell::getEffects() const
{
	return this->_effects;
}

void	ASpell::launch(ATarget const& target) const
{
	target.getHitBySpell(*this);
}
