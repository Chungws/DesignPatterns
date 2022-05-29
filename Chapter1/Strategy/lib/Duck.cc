#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

Duck::Duck( FlyBehavior* flyBehavior, QuackBehavior* quackBehavior) :
  _flyBehavior(flyBehavior), _quackBehavior(quackBehavior)
{
  cout << "Duck::Duck" << endl;
}

Duck::~Duck() { cout << "Duck::~Duck" << endl; }

void Duck::setFlyBehavior(FlyBehavior* fb)
{
  cout << "Duck::setFlyBehavior" << endl;
  _flyBehavior = std::unique_ptr<FlyBehavior>(fb);
}

void Duck::setQuackBehavior(QuackBehavior* qb)
{
  cout << "Duck::setQuackBehavior" << endl;
  _quackBehavior = std::unique_ptr<QuackBehavior>(qb);
}

void Duck::performFly() const
{ 
  cout << "Duck::performFly" << endl;
  _flyBehavior->fly();
}

void Duck::performQuack() const
{
  cout << "Duck::performQuack" << endl;
  _quackBehavior->quack();
}

void Duck::swim() const
{
  cout << "Duck::swim" << endl;
  cout << "All ducks float!" << endl;
}