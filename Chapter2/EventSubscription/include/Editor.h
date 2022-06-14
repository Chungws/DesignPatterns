#pragma once

#include "ObserverManager.h"
#include <memory>
#include <string>

using std::string;

class Editor {
    std::unique_ptr<ObserverManager> manager;
    string _filePath;

  public:
    Editor(string filePath);
    void subscribe(string eventType);
    void open();
    void save();
};