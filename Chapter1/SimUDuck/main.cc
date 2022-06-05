#include "Duck.h"
#include "MallardDuck.h"
#include "ModelDuck.h"
#include "FlyRocketPowered.h"
#include <memory>

int main(int argc, char* argv[]) {
  std::unique_ptr<MallardDuck> mallard(new MallardDuck());
  mallard->display();
  mallard->performFly();
  mallard->performQuack();

  std::unique_ptr<ModelDuck> model(new ModelDuck());
  model->display();
  model->performFly();
  model->performQuack();
  model->setFlyBehavior(new FlyRocketPowered());
  model->performFly();
}