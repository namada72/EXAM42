#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph","turned into a critter") {}

Polymorph::~Polymorph(){}

Polymorph::Polymorph(Polymorph const &src) : ASpell(src) {}

Polymorph &Polymorph::operator=(Polymorph const &src) {
	if(this != &src) {
		_name = src._name;
		_effects = src._effects;
		}
	return *this;
}
	
ASpell* Polymorph::clone() const { return new Polymorph(*this);}


