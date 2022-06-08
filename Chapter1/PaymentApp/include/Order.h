#pragma once

#include "PayStrategy.h"
#include <map>
#include <memory>
#include <string>

using std::map;
using std::string;

class Order {
    std::unique_ptr<PayStrategy> _payStrategy;
    map<string, int> _shoppingList;
    map<string, int> _itemList;
    int calculateTotalAmount();

  public:
    Order(map<string, int> itemList);
    void setPayStrategy(PayStrategy *ps);
    bool payByPayStrategy();
    void addItem(string name, int count);
    void deleteItem(string name);
    void getShoppingList();
};