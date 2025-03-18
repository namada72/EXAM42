#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget {
		
	public:
		Dummy();
		Dummy(Dummy const &src);
		Dummy &operator=(Dummy const &src);
		virtual ~Dummy();

		ATarget* clone() const;
		
};

