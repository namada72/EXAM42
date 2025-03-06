# ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string	_type;
		
	public:
		ATarget(std::string const &type);
		ATarget(ASpell const &src);
		ATarget &operator=(ASpell const &src);
		virtual ~ATarget();

		const std::string & getType() const;

		virtual ATarget* clone() const = 0;

		void getHitBySpell(ASpell const &aspell) const;

		
};
#endif


