#include "ASpell.hpp"
ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects) {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

ASpell::~ASpell(){
	//std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string & ASpell::getName() const{ return _name; }
		
const std::string & ASpell::getEffects() const { return _effects; }


void ASpell::setTitle(std::string const &newtitle) {_title = newtitle; }

void ASpell::introduce() const{
std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


void ASpell::launch (ATarget const & target) const {
	target.getHitBySpell(*this);
}
