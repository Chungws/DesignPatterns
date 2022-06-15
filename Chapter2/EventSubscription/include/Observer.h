#pragma once
#include <string>

using std::string;

class Observer {
  public:
    virtual void update(string eventType, string filePath) = 0;
};