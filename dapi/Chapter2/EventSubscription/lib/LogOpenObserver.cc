#include "LogOpenObserver.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

LogOpenObserver::LogOpenObserver(string path) : _path(path) {}

void LogOpenObserver::update(string eventType, string filePath) {
    cout << filePath << "'s " << eventType << " event is occured, log saved in "
         << _path << endl;
}