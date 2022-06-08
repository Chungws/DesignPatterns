#pragma once

#include "CreditCard.h"
#include "PayStrategy.h"
#include <memory>
#include <string>

using std::string;

class PayByCreditCard : public PayStrategy {
    std::unique_ptr<CreditCard> _creditCard;
    bool isCardRegistered;
    bool payable;
    bool checkCreditCard();
    void setCreditCard(CreditCard *card);

  public:
    PayByCreditCard();
    bool pay(int amount);
    void collectPaymentInfo();
    void registerCreditCard();
};