#include "ModelDuck.h"

#include <iostream>

#include "Duck.h"
#include "FlyNoWay.h"
#include "Quack.h"

using std::cout;
using std::endl;

ModelDuck::ModelDuck() : Duck(new FlyNoWay(), new Quack()) 
{
  //cout << "ModelDuck::ModelDuck" << endl;
}

void ModelDuck::display() const {
  //cout << "ModelDuck::display" << endl;
  cout << "I'am a ModelDuck" << endl;
}