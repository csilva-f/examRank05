#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(std::string const& name, std::string const& title): _name(name), _title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock& other)
{
	*this = other;
}

Warlock	&Warlock::operator=(const Warlock& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_title = other._title;
	}
	return *this;
}

Warlock::~Warlock()
{
	std::cout << this->getName() << ": My job here is done!" << std::endl;
}

std::string const&	Warlock::getName(void) const
{
	return (this->_name);
}

std::string const&	Warlock::getTitle(void) const
{
	return (this->_title);
}

void	Warlock::setTitle(std::string const& title)
{
	this->_title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!\n";
}

void	Warlock::learnSpell(ASpell* spell)
{
	this->_spellBook.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string name)
{
	this->_spellBook.forgetSpell(name);
}

void	Warlock::launchSpell(std::string name, ATarget const& target)
{
	if (this->_spellBook.createSpell(name))
		this->_spellBook.createSpell(name)->launch(target);
}
