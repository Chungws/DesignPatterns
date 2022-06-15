#pragma once

#include "Observable.h"
#include "Observer.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

class ObserverManager : public Observable {
    map<string, vector<std::shared_ptr<Observer>>> observers;

  public:
    ObserverManager();
    void registerObserver(string eventType, std::shared_ptr<Observer> o);
    void removeObserver(string eventType, std::shared_ptr<Observer> o);
    void notifyObservers(string eventType, string filePath);

  private:
    bool verifyEventType(string eventType);
};