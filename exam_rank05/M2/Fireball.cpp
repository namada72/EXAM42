#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

Fireball::~Fireball(){
	//std::cout << _name << ": My job here is done!" << std::endl;
}

Fireball::Fireball(Fireball const &src) : ASpell(src){}

Fireball &Fireball::operator=(Fireball const &src) {
	if (this != &src) {
		_name = src._name;
		_effects = src._effects;
	}
	return (*this);
}

Fireball* Fireball::clone() const {
	return new Fireball(*this);	
}
