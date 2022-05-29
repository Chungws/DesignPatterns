#pragma once

class FlyBehavior {
 public:
  virtual ~FlyBehavior();
  virtual void fly() const = 0;
};