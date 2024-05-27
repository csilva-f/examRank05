#pragma once

# include <iostream>
# include <string>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
	std::string	_name;
	std::string	_effects;

public:
	ASpell();
	ASpell(std::string name, std::string effects);
	ASpell(const ASpell& other);
	ASpell	&operator=(const ASpell& other);
	virtual ~ASpell();

	std::string	getName() const;
	std::string	getEffects() const;

	virtual ASpell*	clone() const = 0;

	void	launch(ATarget const& tarfet) const;
};
