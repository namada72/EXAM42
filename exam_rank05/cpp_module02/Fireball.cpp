#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball","burnt to a crisp") {}

Fireball::~Fireball(){}

Fireball::Fireball(Fireball const &src) : ASpell(src) {}

Fireball &Fireball::operator=(Fireball const &src) {
	if(this != &src) {
		_name = src._name;
		_effects = src._effects;
		}
	return *this;
}
	
ASpell* Fireball::clone() const { return new Fireball(*this);}


