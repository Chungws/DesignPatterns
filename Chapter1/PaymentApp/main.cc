#include "Order.h"
#include "PayByCreditCard.h"
#include "PayByPayPal.h"
#include "PayStrategy.h"

#include <iostream>
#include <map>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main(int argc, char *argv[]) {
    map<string, int> menu;
    string payment;
    menu.emplace("Mother Board", 30);
    menu.emplace("CPU", 70);
    menu.emplace("HDD", 50);
    menu.emplace("Memory", 40);
    auto order = std::make_unique<Order>(menu);

    while (true) {
        string name;
        int count;
        bool find = false;
        string answer;

        cout << "*** Computer Parts Mall ***" << endl;
        cout << "Mother Board : 30 Units" << endl
             << "CPU          : 70 Units" << endl
             << "HDD          : 50 Units" << endl
             << "Memory       : 40 Units" << endl;
        cout << "Please, select a product by type name" << endl;

        getline(cin, name);
        for (auto it = menu.begin(); it != menu.end(); ++it) {
            if (name == it->first) {
                find = true;
            }
        }
        if (!find) {
            cout << "The item is not in menu!" << endl;
            continue;
        }
        cout << "Count: ";
        cin >> count;
        order->addItem(name, count);

        order->getShoppingList();

        cout << "Do you wish to continue selecting products? Y/N: ";
        cin >> answer;

        if (answer == "Y" || answer == "y") {
            continue;
        } else {
            break;
        }
    }

    while (true) {
        cout << "Please, select a payment method:" << endl;
        cout << "PayPal" << endl << "Credit Card" << endl;
        getline(cin, payment);
        if (payment != "PayPal" && payment != "Credit Card") {
            cout << "Please Select Correct Payment Method" << endl;
            continue;
        }
        break;
    }

    if (payment == "PayPal") {
        order->setPayStrategy(new PayByPayPal());
    } else if (payment == "Credit Card") {
        order->setPayStrategy(new PayByCreditCard());
    }

    if (order->payByPayStrategy()) {
        cout << "Payment has been successful." << endl;
    }
}