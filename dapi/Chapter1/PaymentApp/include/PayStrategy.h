#pragma once

class PayStrategy {
  public:
    virtual bool pay(int amount) = 0;
    virtual void collectPaymentInfo() = 0;
};