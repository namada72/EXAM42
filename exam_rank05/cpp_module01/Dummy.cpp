#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy(){}

Dummy::Dummy(Dummy const &src) : ATarget(src) {}

Dummy &Dummy::operator=(Dummy const &src) {
	if(this != &src) {
		_type = src._type;
		}
	return *this;
}
	
ATarget* Dummy::clone() const {return new Dummy(*this);}


