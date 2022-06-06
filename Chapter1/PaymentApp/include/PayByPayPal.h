#pragma once

#include "PayStartegy.h"
#include <map>
#include <string>

using std::map;
using std::string;

class PayByPayPal : public PayStrategy {
    map<string, string> _accountMap;
    bool payable;
    bool findPayPalAccount(string email);
    bool checkPassWord(string email, string pw);

  public:
    PayByPayPal();
    void pay(int amount);
    void collectPaymentInfo();
    void registerPayPalAccount();
    void deletePayPalAccount(string email);
};