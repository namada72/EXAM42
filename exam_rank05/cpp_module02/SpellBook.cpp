#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook(){
	for(std::map<std::string,ASpell*>::iterator it = _spells.begin(); it != _spells.end();++it) {
		delete it->second;
	}
	_spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
	if(spell) {
		std::map<std::string, ASpell*>::iterator it = _spells.find(spell->getName());
		if (it == _spells.end()) {
			_spells[spell->getName()] = spell->clone();
		}
	}
}			

void SpellBook::forgetSpell(std::string spellname) {
		std::map<std::string, ASpell*>::iterator it = _spells.find(spellname);
		if (it != _spells.end())
			_spells.erase(it);
}


ASpell* SpellBook::createSpell(std::string const &spellname) {
		std::map<std::string, ASpell*>::iterator it = _spells.find(spellname);
		if (it != _spells.end()) {
			return it->second->clone();
		}
		return NULL;

}
