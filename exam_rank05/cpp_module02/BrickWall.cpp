#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall(){}

BrickWall::BrickWall(BrickWall const &src) : ATarget(src) {}

BrickWall &BrickWall::operator=(BrickWall const &src) {
	if(this != &src) {
		_type = src._type;
		}
	return *this;
}
	
ATarget* BrickWall::clone() const {return new BrickWall(*this);}


