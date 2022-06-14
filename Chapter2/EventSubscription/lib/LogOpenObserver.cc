#include "LogOpenObserver.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

LogOpenObserver::LogOpenObserver(string path) : _path(path) {}

void LogOpenObserver::update(string eventType, string filePath) {
	cout << filePath << "'s " << eventType << " event is occured, log saved in " << _path << endl; 
}