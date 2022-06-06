#pragma once

#include "PayStartegy.h"
#include <map>
#include <memory>
#include <string>

using std::map;
using std::string;

class Order {
    std::unique_ptr<PayStrategy> _payStrategy;
    map<string, int> _shoppingList;
    std::unique_ptr<map<string, int>> _itemList;
    Order(map<string, int> *itemList);
    int calculateTotalAmount();

  public:
    void setPayStrategy(PayStrategy *ps);
    void payByPayStrategy();
    void addItem(string name, int count);
    void deleteItem(string name);
    void getShoppingList();
};