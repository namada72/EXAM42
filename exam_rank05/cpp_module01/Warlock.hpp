#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
private:
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell*>	_spells;

	Warlock();
	Warlock(Warlock const &src);
	Warlock &operator=(Warlock const &src);

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &newtitle);

	void introduce() const;

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string spellname);
	void launchSpell(std::string spellname, ATarget const &target);
};

