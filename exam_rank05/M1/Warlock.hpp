# ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock {
	private:
		std::string	_name;
		std::string	_title;
		Warlock(Warlock const &src);
		Warlock &operator=(Warlock const &src);
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		const std::string & getName() const;
		const std::string & getTitle() const;

		void setTitle(std::string const &newtitle);

		void introduce() const;
};
#endif


