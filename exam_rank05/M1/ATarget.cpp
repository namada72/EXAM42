#include "ATarget.hpp"
ATarget::ATarget(std::string const &type) : _type(type) {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

ATarget::~ATarget(){
	//std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string & ATarget::getType() const{ return _type; }

ATarget::ATarget(ATarget const &src) : _type(src._type){}

ATarget::ATarget &operator=(ATarget const &src){
	if (this != &src){
		_type = src._type;
	}
	return *this;
}

void ATarget::getHitBySpell(ASpell const &aspell) const { 
	std::cout << _type  << " has been " << aspell.getEffects() << "!" << std::endl;
	std::cout << _type  << " is the ATarget's type, and " << aspell.getEffects() << "!" << std::endl;
}
