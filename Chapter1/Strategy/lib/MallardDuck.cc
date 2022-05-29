#include "MallardDuck.h"

#include <iostream>

#include "Duck.h"
#include "FlyWithWings.h"
#include "Quack.h"

using std::cout;
using std::endl;

MallardDuck::MallardDuck() : Duck(new FlyWithWings(), new Quack()) {
  cout << "MallardDuck::MallardDuck" << endl;
}

void MallardDuck::display() const {
  cout << "MallardDuck::display" << endl;
  cout << "I'am a MallardDuck" << endl;
}