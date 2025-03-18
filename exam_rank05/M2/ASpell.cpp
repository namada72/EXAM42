#include "ASpell.hpp"
ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects) {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

ASpell::~ASpell(){
	//std::cout << _name << ": My job here is done!" << std::endl;
}

ASpell::ASpell(ASpell const &src) : _name(src._name),_effects(src._effects){} 

ASpell &ASpell::operator=(ASpell const &src) {
	if(this != &src)
	{
		_name = src._name;
		_effects = src._effects;
	}
	return *this;
}

const std::string & ASpell::getName() const{ return _name; }
		
const std::string & ASpell::getEffects() const { return _effects; }

void ASpell::launch (ATarget const & target) const {
	target.getHitBySpell(*this);
}
