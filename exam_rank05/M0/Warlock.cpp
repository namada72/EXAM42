#include "Warlock.hpp"

Warlock::Warlock() : _name("Default"), _title("Default"){}

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
	std::cout << _name << " : This looks like another boring day." << std::endl;	
}

Warlock::~Warlock(){
	std::cout << _name << " : My job here is done!" << std::endl;
}

Warlock::Warlock(Warlock const &src): _name(src._name), _title(src._title) {}

Warlock::Warlock &operator=(Warlock const &src){
	if (this != &src){
		_name = src._name;
		_title = src._title;
	}
	return *this;
}

std::string & Warlock::getName() const{ return _name; }
		
std::string & Warlock::getTitle() const { return _title; }

void Warlock::setTitle(std::string const &newtitle) {_title = newtitle; }

void Warlock::introduce() const{
	std::cout << "I am " << _name << ", " << _title << "!" << stad::endl;
}
