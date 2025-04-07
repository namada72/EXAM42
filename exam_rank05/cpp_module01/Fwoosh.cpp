#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh","fwooshed") {}

Fwoosh::~Fwoosh(){}

Fwoosh::Fwoosh(Fwoosh const &src) : ASpell(src) {}

Fwoosh &Fwoosh::operator=(Fwoosh const &src) {
	if(this != &src) {
		_name = src._name;
		_effects = src._effects;
		}
	return *this;
}
	
ASpell* Fwoosh::clone() const { return new Fwoosh(*this);}


