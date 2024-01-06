#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Observer {
public:
    virtual void update() = 0;
};

class Device : public Observer {
public:
    string name;

    Device(string name) {
        this->name = name;
    }

    void update()  {
        cout << "Updated on device " << name << "\n";
    }
};

class Observable {
public:
    virtual void addObserver(Observer* obs) = 0;
    virtual void notify() = 0;
    virtual void update()=0;
};

class Weather : public Observable {
    vector<Observer*> observers;
    int val;

public:
Weather(){
    val=0;
}
    void addObserver(Observer* obs)  {
        observers.push_back(obs);
    }

    void notify()  {
        for (Observer* x : observers) {
            x->update();
        }
    }

    void update() {
        this->val = 500;
        notify();
    }
};

int main() {
    Device device1("iphone 15pro max");
    Device device2("iphone 14pro");
    Weather ws;

    // Add devices as observers
    ws.addObserver(&device1);
    ws.addObserver(&device2);

    // Trigger update on Weather, which will notify the devices
    ws.update();

    return 0;
}
