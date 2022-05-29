#include <iostream>

#include "Squeak.h"

void Squeak::quack() const {
  std::cout << "Squeak::quack" << std::endl;
  std::cout << "Squeak!" << std::endl;
}