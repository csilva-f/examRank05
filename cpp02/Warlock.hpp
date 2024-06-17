#pragma once

# include <iostream>
# include <string>
# include <map>
# include "ASpell.hpp"
# include "SpellBook.hpp"

class Warlock
{
private:
	std::string	_name;
	std::string	_title;
	SpellBook	_spellBook;
	
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
	void	forgetSpell(std::string spell);
	void	launchSpell(std::string spell, const ATarget& target);
};
