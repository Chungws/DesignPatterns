#include "ObserverManager.h"
#include "Observer.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::find;
using std::map;
using std::string;
using std::vector;

ObserverManager::ObserverManager() : observers() {
    vector<std::unique_ptr<Observer>> openVector, saveVector;
    observers["open"] = openVector;
    observers["save"] = saveVector;
}

void ObserverManager::registerObserver(string eventType, Observer *o) {
    if (!verifyEventType(eventType)) {
        return;
    }
    observers[eventType].push_back(std::unique_ptr<Observer>(o));
    cout << "Observer is Registered!" << endl;
}

void ObserverManager::removeObserver(string eventType, Observer *o) {
    if (!verifyEventType(eventType)) {
        return;
    }
    auto it = find(observers[eventType].begin(), observers[eventType].end(), o);
    if (it == observers[eventType].end()) {
        cout << "This observer is not registered in this event type." << endl;
        return;
    }
    observers[eventType].erase(it);
    cout << "Observer is removed in " << eventType << " event type!" << endl;
}

void ObserverManager::notifyObservers(string eventType) {
    if (!verifyEventType(eventType)) {
        return;
    }
    cout << eventType << " event is occured!" << endl;
    for (auto it = observers[eventType].begin();
         it != observers[eventType].end(); ++it) {
        it->get()->update();
    }
}

bool ObserverManager::verifyEventType(string eventType) {
    if (observers.find(eventType) != observers.end()) {
        cout << "Event Type Verified" << endl;
        return true;
    }
    cout << "Event Type Wrong!" << endl;
    return false;
}