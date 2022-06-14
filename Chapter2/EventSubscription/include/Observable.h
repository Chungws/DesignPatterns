#pragma once

class Observable {
  public:
    virtual void registerObserver() = 0;
    virtual void removeObserver() = 0;
    virtual void NotifyObservers() = 0;
};