#pragma once


#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
	private:
		std::string	_name;
		std::string	_title;
	
		Warlock(Warlock const &src);
	
		Warlock &operator=(Warlock const &src);

		//std::map<std::string,ASpell*> _spells;
		SpellBook _spellBook;
	
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		const std::string & getName() const;
		const std::string & getTitle() const;

		void setTitle(std::string const &newtitle);

		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget const &target);


};


