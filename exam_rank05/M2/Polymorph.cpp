#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

Polymorph::~Polymorph(){
	//std::cout << _name << ": My job here is done!" << std::endl;
}

Polymorph::Polymorph(Polymorph const &src) : ASpell(src){}

Polymorph &Polymorph::operator=(Polymorph const &src) {
	if (this != &src) {
		_name = src._name;
		_effects = src._effects;
	}
	return (*this);
}

Polymorph* Polymorph::clone() const {
	return new Polymorph(*this);	
}
