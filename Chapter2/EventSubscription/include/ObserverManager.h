#pragma once

#include "Observable.h"
#include "Observer.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

using std::map;
using std::string;

class ObserverManager : public Observable {
    map<string, vector<std::unique_ptr<Observer>>> observers;

  public:
    ObserverManager();
    void registerObserver(string eventType, Observer *o);
    void removeObserver(string eventType, Observer *o);
    void notifyObservers(string eventType);

  private:
    bool verifyEventType(string eventType);
};