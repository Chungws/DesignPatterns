#include "CreditCard.h"
#include <string>

using std::string;

CreditCard::CreditCard(string number, string date, string cvc, string pw)
    : _number(number), _date(date), _cvc(cvc), _pw(pw) {}

bool CreditCard::checkNumber(string number) {
    return (_number.compare(number) == 0);
}

bool CreditCard::checkDate(string date) { return (_date.compare(date) == 0); }

bool CreditCard::checkCvc(string cvc) { return (_cvc.compare(cvc) == 0); }

bool CreditCard::checkPw(string pw) { return (_pw.compare(pw) == 0); }