#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fwoosh : public ASpell{
public:
	Fwoosh();
	~Fwoosh();
	Fwoosh(Fwoosh const &src);
	Fwoosh &operator=(Fwoosh const &src);


	ASpell* clone() const;

};

