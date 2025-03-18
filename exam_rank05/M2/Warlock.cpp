#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;	
}

Warlock::~Warlock(){
	// std::cout << _name << ": My job here is done!" << std::endl;
	// //libero memoria hechizos aprendidos
	// for(std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it){
	// delete it->second;
	// }
	// _spells.clear();
}

const std::string & Warlock::getName() const{ return _name; }
		
const std::string & Warlock::getTitle() const { return _title; }

void Warlock::setTitle(std::string const &newtitle) {_title = newtitle; }

void Warlock::introduce() const{
std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell){
	// if(spell)
	// {
	// 	if((_spells.find(spell->getName())) == _spells.end()) {
	// 		_spells[spell->getName()] = spell->clone();
	// 	}
	// }
	_spellBook.learnSpell(spell);
}


void Warlock::forgetSpell(std::string spellName){
	// std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
	// if (it !=_spells.end()) {
	// 	//delete it->second;
	// 	_spells.erase(it);
	// }
	_spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget const &target){
	
	// std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
	// if (it !=_spells.end() ){
	// 	it->second->launch(target);
	// }
	ASpell* castSpell = _spellBook.createSpell(spellName);
	if (castSpell){
		castSpell->launch(target);
	}
	delete castSpell;
}
