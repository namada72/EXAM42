#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Polymorph : public ASpell{
public:
	Polymorph();
	~Polymorph();
	Polymorph(Polymorph const &src);
	Polymorph &operator=(Polymorph const &src);


	ASpell* clone() const;

};

