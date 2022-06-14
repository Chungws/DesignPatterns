#include "Editor.h"
#include "ObserverManager.h"
#include "LogOpenObserver.h"
#include "EmailNotificationObserver.h"
#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

Editor::Editor(string filePath) : _filePath(filePath), manager(std::make_unique<ObserverManager>()) {
	cout << "Editor is Created!" << endl << "file: " << _filePath << endl;
}

void Editor::open() {
	cout << _filePath << " is opened!" << endl;
	manager->notifyObservers("open");
}

void Editor::save() {
	cout << _filePath << " is saved!" << endl;
	manager->notifyObservers("save");
}

void Editor::subscribe(string eventType) {
	cout << "Subscribe editor by an observer" << endl;
	cout << "Please select observing mode" << endl
		<< "1 - log" << endl << "2 - email" << endl;
	string mode;
	cin >> mode;
	if (mode != "1" && mode != "2") {
		cout << "Wrong Number" << endl;
		return;
	}
	if (mode == "1") {
		string logPath;
		cout << "Please enter the log file's path" << endl;
		getline(cin, logPath);
		manager.registerObserver(eventType, new LogOpenObserver(logPath));
	} else if (mode == "2") {
		string email;
		cout << "Please enter the email" << endl;
		getline(cin, email);
		manager.registerObserver(eventType, new EmailNotificationObserver(email));
	}
}