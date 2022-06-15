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
    vector<std::shared_ptr<Observer>> openVector, saveVector;
    observers.emplace("open", openVector);
    observers.emplace("save", saveVector);
    // observers["open"] = openVector;
    // observers["save"] = saveVector;
}

void ObserverManager::registerObserver(string eventType,
                                       std::shared_ptr<Observer> o) {
    if (!verifyEventType(eventType)) {
        return;
    }
    observers[eventType].push_back(o);
    cout << "Observer is Registered!" << endl;
}

void ObserverManager::removeObserver(string eventType,
                                     std::shared_ptr<Observer> o) {
    if (!verifyEventType(eventType)) {
        return;
    }
    auto const it =
        find(observers[eventType].begin(), observers[eventType].end(), o);
    if (it == observers[eventType].end()) {
        cout << "This observer is not registered in this event type." << endl;
        return;
    }
    observers[eventType].erase(it);
    cout << "Observer unsubscribe " << eventType << " event type!" << endl;
}

void ObserverManager::notifyObservers(string eventType, string filePath) {
    if (!verifyEventType(eventType)) {
        return;
    }
    for (auto it = observers[eventType].begin();
         it != observers[eventType].end(); ++it) {
        it->get()->update(eventType, filePath);
    }
}

bool ObserverManager::verifyEventType(string eventType) {
    if (observers.find(eventType) != observers.end()) {
        return true;
    }
    cout << "Event Type Wrong!" << endl;
    return false;
}