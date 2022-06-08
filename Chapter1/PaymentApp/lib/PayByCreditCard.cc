#include "PayByCreditCard.h"
#include "CreditCard.h"
#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

PayByCreditCard::PayByCreditCard() : payable(false), isCardRegistered(false) {}

bool PayByCreditCard::pay(int amount) {
    collectPaymentInfo();

    if (!payable) {
        cout << "Can't pay!" << endl;
        return false;
    }
    cout << "Paying " << amount << " units by Credit Card" << endl;
    payable = false;
    return true;
}

void PayByCreditCard::collectPaymentInfo() {
    string number;
    string pw;

    while (true) {
        if (!isCardRegistered) {
            string command;
            cout << "Please Regist Card First" << endl;
            cout << "If You Want, Type Any Words" << endl;
            cout << "If You Don't Want, Type exit or 0" << endl;
            cin >> command;
            if (command.compare("exit") == 0 || command.compare("0") == 0) {
                cout << "Payment Cancelled!" << endl;
                return;
            }
            registerCreditCard();
            continue;
        } else {
            cout << "Please Enter Your Credit Card Number" << endl;
            cin >> number;
            cout << "Please Enter Your Credit Card Password" << endl;
            cin >> pw;
            if (!_creditCard->checkNumber(number)) {
                cout << "Wrong Number!" << endl;
                continue;
            }
            if (!_creditCard->checkPw(pw)) {
                cout << "Wrong Password!" << endl;
                continue;
            }
            break;
        }
    }

    cout << "Verified!" << endl;
    payable = true;
}

void PayByCreditCard::registerCreditCard() {
    string number;
    string date;
    string cvc;
    string pw;

    cout << "Register Your Credit Card!" << endl;
    cout << "Please Enter Your Credit Card Number" << endl;
    cin >> number;

    cout << "Please Enter Your Credit Card Expire Date" << endl;
    cin >> date;

    cout << "Please Enter Your Credit Card CVC Number" << endl;
    cin >> cvc;

    cout << "Please Enter Your Credit Card Password" << endl;
    cin >> pw;

    setCreditCard(new CreditCard(number, date, cvc, pw));
    isCardRegistered = true;

    cout << "Your Credit Card is Registered!" << endl;
}

void PayByCreditCard::setCreditCard(CreditCard *card) {
    _creditCard = std::unique_ptr<CreditCard>(card);
}