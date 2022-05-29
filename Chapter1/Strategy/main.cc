#include "Duck.h"
#include "MallardDuck.h"
#include <memory>

int main(int argc, char* argv[]) {
  std::unique_ptr<MallardDuck> mallard(new MallardDuck());
  mallard->performFly();
  mallard->performQuack();
}