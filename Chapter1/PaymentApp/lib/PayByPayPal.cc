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

// flag 최소화하기

bool PayByPayPal::pay(int amount) {
    collectPaymentInfo();

    if (!payable) {
        cout << "Can't pay!" << endl;
        return false;
    }
    cout << "Paying " << amount << " units by PayPal" << endl;
    payable = false;
    return true;
}

void PayByPayPal::collectPaymentInfo() {
    string email;
    string pw;

    while (true) {
        cout << "Please Enter Your PayPal Account Email" << endl;
        cin >> email;
        if (!findPayPalAccount(email)) {
            string command;
            cout << "Your Email is not Registered! Please Regist First" << endl;
            cout << "If You Want, Type Any Words" << endl;
            cout << "If You Don't Want, Type exit or 0" << endl;
            cin >> command;
            if (command.compare("exit") == 0 || command.compare("0") == 0) {
                cout << "Payment Cancelled!" << endl;
                return;
            }
            registPayPalAccount();
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

void PayByPayPal::registPayPalAccount() {
    string email;
    string pw;

    while (true) {
        cout << "Regist Your PayPal Account!" << endl;
        cout << "Please Enter Your PayPal Account Email" << endl;
        cin >> email;
        if (findPayPalAccount(email)) {
            cout << "Your Email is already Registered!" << endl;
            continue;
        }
        break;
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