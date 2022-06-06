#pragma once

#include "CreditCard.h"
#include "PayStartegy.h"
#include <memory>
#include <string>

using std::string;

class PayByCreditCard : public PayStrategy {
    std::unique_ptr<CreditCard> _creditCard;
    bool isCardRegistered;
    bool payable;
    bool checkCreditCard();

  public:
    PayByCreditCard();
    void pay(int amount);
    void collectPaymentInfo();
    void registerCreditCard();
    void setCreditCard();
    void deleteCreditCard();
};