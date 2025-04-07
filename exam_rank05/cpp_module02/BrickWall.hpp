#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class BrickWall : public ATarget{
public:
	BrickWall();
	~BrickWall();
	BrickWall(BrickWall const &src);
	BrickWall &operator=(BrickWall const &src);


	ATarget* clone() const;

};

