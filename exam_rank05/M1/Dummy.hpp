# ifndef DUMMY_HPP
# define DUMMY_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget {
		
	public:
		Dummy();
		Dummy(Dummy const &src);
		Dummy &operator=(Dummy const &src);
		virtual ~Dummy();

		virtual Dummy* clone() const;
		
};
#endif


