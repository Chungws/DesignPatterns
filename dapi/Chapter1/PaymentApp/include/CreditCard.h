#pragma once

#include <string>

using std::string;

class CreditCard {
    string _number;
    string _date;
    string _cvc;
    string _pw;

  public:
    CreditCard(string number, string date, string cvc, string pw);
    bool checkNumber(string number);
    bool checkDate(string date);
    bool checkCvc(string cvc);
    bool checkPw(string pw);
};