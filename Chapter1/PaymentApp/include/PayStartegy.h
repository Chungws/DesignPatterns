#pragma once

class PayStrategy {
  public:
    virtual void pay(int amount) = 0;
    virtual void collectPaymentInfo() = 0;
};