#include "SpellBook.hpp"

SpellBook::SpellBook() {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

SpellBook::~SpellBook(){
	//std::cout << _name << ": My job here is done!" << std::endl;
	//libero memoria hechizos aprendidos
	for(std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it){
	delete it->second;
	}
	_spells.clear();
}

//const std::string & SpellBook::getName() const{ return _name; }
		
//const std::string & SpellBook::getTitle() const { return _title; }

//void SpellBook::setTitle(std::string const &newtitle) {_title = newtitle; }

// void SpellBook::introduce() const{
// std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
// }

void SpellBook::learnSpell(ASpell *spell){
	if(spell)
	{
		if((_spells.find(spell->getName())) == _spells.end()) {
			_spells[spell->getName()] = spell->clone();
		}
	}
}


void SpellBook::forgetSpell(std::string spellName){
	std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
	if (it !=_spells.end()) {
		//delete it->second;
		_spells.erase(it);
	}
}

// void SpellBook::launchSpell(std::string spellName, ATarget const &target){
	
// 	std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
// 	if (it !=_spells.end() ){
// 		it->second->launch(target);
// 	}
// }

ASpell* SpellBook::createSpell(std::string const &spell) {
	std::map<std::string, ASpell*>::iterator it = _spells.find(spell);
	if (it != _spells.end()) {
		return it->second->clone();
	}
	return NULL;
}