#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
	private:
	
		SpellBook(SpellBook const &src);
	
		SpellBook &operator=(SpellBook const &src);

		std::map<std::string,ASpell*> _spells;
	
	public:
		SpellBook();
		~SpellBook();

//		const std::string & getName() const;
//		const std::string & getTitle() const;

//		void setTitle(std::string const &newtitle);

//		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
//		void launchSpell(std::string spellName, ATarget const &target);

		ASpell* createSpell(std::string const &spell);

};


