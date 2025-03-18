#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

Dummy::~Dummy(){
	//std::cout << _name << ": My job here is done!" << std::endl;
}

Dummy::Dummy(Dummy const &src) : ATarget(src){}

Dummy &Dummy::operator=(Dummy const &src){
	if (this != &src){
		_type = src._type;
	}
	return *this;
}

ATarget *Dummy::clone() const {
	return new Dummy(*this);
}
