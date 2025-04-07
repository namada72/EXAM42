#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
	std::string _name;
	std::string _effects;

	ASpell();
public:
	ASpell(std::string const &name, std::string const &effects);
	virtual ~ASpell();
	ASpell(ASpell const &src);
	ASpell &operator=(ASpell const &src);

	std::string const &getName() const;
	std::string const &getEffects() const;

	virtual ASpell* clone() const = 0;

	void launch(ATarget const &target) const;

};

