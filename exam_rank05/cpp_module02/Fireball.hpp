#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fireball : public ASpell{
public:
	Fireball();
	~Fireball();
	Fireball(Fireball const &src);
	Fireball &operator=(Fireball const &src);


	ASpell* clone() const;

};

