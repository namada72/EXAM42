#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"

class ATarget;

class Fireball : public ASpell {

	public:
		Fireball();
		Fireball(Fireball const &src);
		Fireball &operator=(Fireball const &src);
		virtual ~Fireball();

		Fireball* clone() const;

		
};


