# ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"

class ATarget;

class Fwoosh : public ASpell {

	public:
		Fwoosh();
		Fwoosh(Fwoosh const &src);
		Fwoosh &operator=(Fwoosh const &src);
		virtual ~Fwoosh();

		virtual Fwoosh* clone() const;

		
};
#endif


