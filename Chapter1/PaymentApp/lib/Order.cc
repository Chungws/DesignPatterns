#include "Order.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

Order::Order(map<string, int> itemList) : _itemList(itemList), _shoppingList() {
    cout << "Set Item List" << endl;
}

void Order::setPayStrategy(PayStrategy *ps) {
    cout << "Set Payment Strategy" << endl;
    _payStrategy = std::unique_ptr<PayStrategy>(ps);
}

bool Order::payByPayStrategy() {
    int totalAmount = calculateTotalAmount();
    if (totalAmount == 0) {
        cout << "There is no items in shopping list" << endl;
        return false;
    }
    return _payStrategy->pay(totalAmount);
}

void Order::addItem(string name, int count) {
    _shoppingList.emplace(name, count);
}

void Order::deleteItem(string name) {
    for (auto it = _shoppingList.begin(); it != _shoppingList.end();) {
        if (it->first == name) {
            _shoppingList.erase(it++);
        } else {
            ++it;
        }
    }
}

void Order::getShoppingList() {
    for (auto it = _shoppingList.begin(); it != _shoppingList.end(); ++it) {
        cout << "item: " << it->first << ", number: " << it->second << endl;
    }
    cout << "total price: " << calculateTotalAmount() << " units" << endl;
}

int Order::calculateTotalAmount() {
    int total = 0;
    for (auto it = _shoppingList.begin(); it != _shoppingList.end(); ++it) {
        // string name = it->first;
        // int count = it->second;
        map<string, int>::iterator fnd = _itemList.find(it->first);
        if (fnd != _itemList.end()) {
            total += fnd->second * it->second;
        }
    }
    return total;
}