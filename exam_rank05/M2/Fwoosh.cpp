#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

Fwoosh::~Fwoosh(){
	//std::cout << _name << ": My job here is done!" << std::endl;
}

Fwoosh::Fwoosh(Fwoosh const &src) : ASpell(src){}

Fwoosh &Fwoosh::operator=(Fwoosh const &src) {
	if (this != &src) {
		_name = src._name;
		_effects = src._effects;
	}
	return (*this);
}

Fwoosh* Fwoosh::clone() const {
	return new Fwoosh(*this);	
}
