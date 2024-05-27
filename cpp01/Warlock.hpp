#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class Warlock
{
private:
	std::string						_name;
	std::string						_title;
	std::map<std::string, ASpell *>	_spells;

	Warlock();
	Warlock(const Warlock& other);
	Warlock	&operator=(const Warlock& other);

public:
	Warlock(std::string const& name, std::string const& title);
	~Warlock();

	std::string const&	getName(void) const;
	std::string const&	getTitle(void) const;

	void	setTitle(std::string const& title);
	void	introduce() const;

	void	learnSpell(ASpell* spell);
	void	forgetSpell(std::string name);
	void	launchSpell(std::string name, ATarget const& target);
};

#endif
