#pragma once

#include "Observer.h"
#include <string>

using std::string;

class LogOpenObserver : public Observer {
    string _path;

  public:
    LogOpenObserver(string path);
    void update();
};