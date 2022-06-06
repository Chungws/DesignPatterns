#include "PayByPayPal.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

PayByPayPal::PayByPayPal() : payable(false), _accountMap() {}

void PayByPayPal::pay(int amount) {
    collectPaymentInfo();

    if (!payable) {
        cout << "Can't pay!" << endl;
        return;
    }
    cout << "Paying " << amount << " units by PayPal" << endl;
    payable = false;
}

void PayByPayPal::collectPaymentInfo() {
    string email;
    string pw;

    while (true) {
        cout << "Please Enter Your PayPal Account Email" << endl;
        cin >> email;
        if (email.compare("exit") == 0 || email.compare("0") == 0) {
            cout << "Payment Cancelled!" << endl;
            return;
        }
        if (!findPayPalAccount(email)) {
            cout << "Your Email is not Registered or Spell Wrong! Please Pay "
                    "Again"
                 << endl;
            cout << "Type exit or 0 Can Cancel the Payment" << endl;
            continue;
        }
        break;
    }

    while (true) {
        cout << "Please Enter Your PayPal Account Password" << endl;
        cin >> pw;
        if (pw.compare("exit") == 0 || pw.compare("0") == 0) {
            cout << "Payment Cancelled!" << endl;
            return;
        }
        if (!checkPassWord(email, pw)) {
            cout << "Password is Wrong! Please Type Again" << endl;
            cout << "Type exit or 0 Can Cancel the Payment" << endl;
            continue;
        }
        break;
    }

    cout << "Account Verified!" << endl;
    payable = true;
}

void PayByPayPal::registerPayPalAccount() {
    string email;
    string pw;

    while (true) {
        cout << "Register Your PayPal Account!" << endl;
        cout << "Please Enter Your PayPal Account Email" << endl;
        cin >> email;
        if (findPayPalAccount(email)) {
            cout << "Your Email is already Registered!" << endl;
            continue;
        }
    }

    cout << "Please Enter Your PayPal Account Password" << endl;
    cin >> pw;

    _accountMap.emplace(email, pw);
    cout << "Your PayPal Account is Registered!" << endl;
}

void PayByPayPal::deletePayPalAccount(string email) {
    for (auto it = _accountMap.begin(); it != _accountMap.end();) {
        if (it->first == email) {
            _accountMap.erase(it++);
            cout << "Your PayPal Account is Deleted!" << endl;
        } else {
            ++it;
        }
    }
}

bool PayByPayPal::findPayPalAccount(string email) {
    for (auto it = _accountMap.begin(); it != _accountMap.end();) {
        if (it->first == email) {
            return true;
        } else {
            ++it;
        }
    }
    return false;
}

bool PayByPayPal::checkPassWord(string email, string pw) {
    for (auto it = _accountMap.begin(); it != _accountMap.end();) {
        if (it->first == email) {
            if (it->second == pw) {
                return true;
            } else {
                return false;
            }
        } else {
            ++it;
        }
    }
    return false;
}