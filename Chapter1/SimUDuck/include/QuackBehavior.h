#pragma once

class QuackBehavior {
 public:
  virtual ~QuackBehavior();
  virtual void quack() const = 0;
};