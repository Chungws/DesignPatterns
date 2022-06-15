#pragma once
#include "Observer.h"
#include <memory>
#include <string>

using std::string;
class Observable {
  public:
    virtual void registerObserver(string eventType,
                                  std::shared_ptr<Observer> o) = 0;
    virtual void removeObserver(string eventType,
                                std::shared_ptr<Observer> o) = 0;
    virtual void notifyObservers(string eventType, string filePath) = 0;
};