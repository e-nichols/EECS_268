#include <iostream>
#include "Dice.h"

int main () {

Dice d(20);

std::cout << "Hello, World! \n";
std::cout << "we throw a dice with number " << d.roll() << "\n";

return 0;
}
