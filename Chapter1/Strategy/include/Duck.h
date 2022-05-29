#include <memory>

#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck {
  std::unique_ptr<FlyBehavior> _flyBehavior;
  std::unique_ptr<QuackBehavior> _quackBehavior;
  Duck();

  protected:
   Duck(FlyBehavior* flyBehavior, QuackBehavior* quackBehavior);

  public:
   virtual ~Duck();
   void setFlyBehavior(FlyBehavior* fb);
   void setQuackBehavior(QuackBehavior* qb);
   void performFly() const;
   void performQuack() const;
   void swim() const;
   virtual void display() const = 0;
};