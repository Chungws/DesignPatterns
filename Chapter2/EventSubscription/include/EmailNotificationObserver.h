#pragma once

#include "Observer.h"
#include <string>

using std::string;

class EmailNotificationObserver : public Observer {
    string _email;

  public:
    EmailNotificationObserver(string email);
    void update(string eventType, string filePath);
};