#include "EmailNotificationObserver.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

EmailNotificationObserver::EmailNotificationObserver(string email) : _email(email) {}

void EmailNotificationObserver::update(string eventType, string filePath) {
	cout << filePath << "'s " << eventType << " event is occured, an email has been sent to " << _email << endl; 
}