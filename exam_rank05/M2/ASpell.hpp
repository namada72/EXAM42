#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		std::string	_name;
		std::string	_effects;

	public:
		ASpell(std::string const &name, std::string const &effects);
		ASpell(ASpell const &src);
		ASpell &operator=(ASpell const &src);
		virtual ~ASpell();

		const std::string & getName() const;
		const std::string & getEffects() const;

		virtual ASpell* clone() const = 0;

		void launch (ATarget const & target) const;

		
};



