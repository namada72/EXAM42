#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
	std::string _type;

	ATarget();
public:
	ATarget(std::string const &type);
	virtual ~ATarget();
	ATarget(ATarget const &src);
	ATarget &operator=(ATarget const &src);

	std::string const &getType() const;

	virtual ATarget* clone() const = 0;

	void getHitBySpell(ASpell const &spell) const;
};

