#include "Warlock.hpp"
#include <iostream>

int main {
	
	Warlock const mago1("Dad","El padre");
	mago1.introduce();
	std::cout << mago1.getName() << " - " << mago1.getTitle() << std::endl;

	Warlock *mago2 = new Warlock("Hijo", "El mejor");
	mago2->introduce();
	std::cout << mago2.getName() << " - " << mago2.getTitle() << std::endl;
	mago2->setTitle("El aprendiz");
	mago2->introduce();

	delete mago2;
	return 0;
}


