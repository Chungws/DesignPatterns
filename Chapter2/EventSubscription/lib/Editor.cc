#include "Editor.h"
#include "EmailNotificationObserver.h"
#include "LogOpenObserver.h"
#include "ObserverManager.h"
#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Editor::Editor(string filePath)
    : _filePath(filePath), manager(std::make_unique<ObserverManager>()) {
    cout << "Editor is Created!" << endl << "file: " << _filePath << endl;
}

void Editor::open() {
    cout << _filePath << " is opened!" << endl;
    manager->notifyObservers("open", _filePath);
}

void Editor::save() {
    cout << _filePath << " is saved!" << endl;
    manager->notifyObservers("save", _filePath);
}

void Editor::subscribe(string eventType) {
    cout << "Subscribe editor by an observer" << endl;
    cout << "Please select observing mode" << endl
         << "1 - log" << endl
         << "2 - email" << endl;
    string mode;
    cin >> mode;
    if (mode != "1" && mode != "2") {
        cout << "Wrong Number" << endl;
        return;
    }
    if (mode == "1") {
        string logPath;
        cout << "Please enter the log file's path" << endl;
        cin >> logPath;
        auto observer = std::make_shared<LogOpenObserver>(logPath);
        manager->registerObserver(eventType, observer);
    } else if (mode == "2") {
        string email;
        cout << "Please enter the email" << endl;
        cin >> email;
        auto observer = std::make_shared<EmailNotificationObserver>(email);
        manager->registerObserver(eventType, observer);
    }
}