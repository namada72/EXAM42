#include <iostream>
#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

Warlock richard("Richard", "the Titled");

Dummy bob;
Fwoosh* fwoosh = new Fwoosh();
richard.learn Spell(fwoosh);

richard.introduce();
richard.launchSpell("Fwoosh", bob);

richard.forgetSpell("Fwoosh");
richard.launchSpell("Fwoosh", bob);

delete fwoosh;
return 0;
}
