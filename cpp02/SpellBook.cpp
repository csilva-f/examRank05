#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook& other)
{
	*this = other;
}

SpellBook	&SpellBook::operator=(const SpellBook& other)
{
	if (this != &other)
		this->_book = other._book;
	return *this;
}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = this->_book.begin(); it != this->_book.end(); ++it)
		delete it->second;
	this->_book.clear();
}

void	SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
		if (this->_book.find(spell->getName()) == this->_book.end())
			this->_book[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell(std::string const& spell)
{
	if (this->_book.find(spell) != this->_book.end())
		this->_book.erase(this->_book.find(spell));
}

ASpell*	SpellBook::createSpell(std::string const& spell)
{
	ASpell*	sp = NULL;
	if (this->_book.find(spell) != this->_book.end())
		sp = this->_book[spell];
	return sp;
}
