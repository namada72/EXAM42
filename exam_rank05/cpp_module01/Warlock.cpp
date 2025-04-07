#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){
	std::cout << _name << ": My job here is done!" << std::endl;
	for(std::map<std::string,ASpell*>::iterator it = _spells.begin(); it != _spells.end();++it) {
		delete it->second;
	}
	_spells.clear();
}

std::string const &Warlock::getName() const { return _name;}
std::string const &Warlock::getTitle() const {return _title;}

void Warlock::setTitle(std::string const &newtitle) {_title= newtitle;} 

void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
	if(spell) {
		std::map<std::string, ASpell*>::iterator it = _spells.find(spell->getName());
		if (it == _spells.end()) {
			_spells[spell->getName()] = spell->clone();
		}
	}
}			

void Warlock::forgetSpell(std::string spellname) {
		std::map<std::string, ASpell*>::iterator it = _spells.find(spellname);
		if (it != _spells.end())
			_spells.erase(it);
}


void Warlock::launchSpell(std::string spellname, ATarget const &target) {
		std::map<std::string, ASpell*>::iterator it = _spells.find(spellname);
		if (it != _spells.end()) {
			it->second->launch(target);
			}
			}
