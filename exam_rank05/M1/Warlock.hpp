# ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class Warlock {
	private:
		std::string	_name;
		std::string	_title;
	
		Warlock(Warlock const &src);
	
		Warlock &operator=(Warlock const &src);

		std::map<std::string,ASpell*> _spells;
	
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		const std::string & getName() const;
		const std::string & getTitle() const;

		void setTitle(std::string const &newtitle);

		void introduce() const;

		void learnSpell(ASpell* const spell);
		void forgetSpell(std::string& const spell);
		void launchSpell(std::string& const spell, ATarget& const target);


};
#endif


