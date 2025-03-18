#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class BrickWall : public ATarget {
		
	public:
		BrickWall();
		BrickWall(BrickWall const &src);
		BrickWall &operator=(BrickWall const &src);
		virtual ~BrickWall();

		ATarget* clone() const;
		
};

