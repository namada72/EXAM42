#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"

class ATarget;

class Polymorph : public ASpell {

	public:
		Polymorph();
		Polymorph(Polymorph const &src);
		Polymorph &operator=(Polymorph const &src);
		virtual ~Polymorph();

		Polymorph* clone() const;

		
};
