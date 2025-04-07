#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class Dummy : public ATarget{
public:
	Dummy();
	~Dummy();
	Dummy(Dummy const &src);
	Dummy &operator=(Dummy const &src);


	ATarget* clone() const;

};

