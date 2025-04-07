#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook {
private:
	std::map<std::string, ASpell*>	_spells;

	SpellBook(SpellBook const &src);
	SpellBook &operator=(SpellBook const &src);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string spellname);
	ASpell* createSpell(std::string const &spellname);
};

