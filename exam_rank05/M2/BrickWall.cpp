#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

BrickWall::~BrickWall(){
	//std::cout << _name << ": My job here is done!" << std::endl;
}

BrickWall::BrickWall(BrickWall const &src) : ATarget(src){}

BrickWall &BrickWall::operator=(BrickWall const &src){
	if (this != &src){
		_type = src._type;
	}
	return *this;
}

ATarget *BrickWall::clone() const {
	return new BrickWall(*this);
}
