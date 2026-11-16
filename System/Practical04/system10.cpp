// OOPVC Practical 4.1: Basic concepts and importance of OO design patterns
// File: system10.cpp
// ALGORITHM:
// 1. Define a Subject and Observer interface with concrete observers.
// 2. Attach observers, change the subject state, and notify all observers.

// Design patterns: why they matter. Demonstrated with the Observer pattern
// (loose coupling, reusability, easy extension).
#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void update(int value) = 0;
    virtual ~Observer() {}
};

class Subject {
    vector<Observer*> observers;
    int state;
public:
    void attach(Observer *o) { observers.push_back(o); }
    void setState(int s) {
        state = s;
        notifyAll();
    }
    void notifyAll() {
        for (size_t i = 0; i < observers.size(); i++) observers[i]->update(state);
    }
};

class DisplayA : public Observer {
public:
    void update(int v) override { cout << "Display A: value changed to " << v << endl; }
};
class DisplayB : public Observer {
public:
    void update(int v) override { cout << "Display B: value squared = " << v * v << endl; }
};

int main() {
    cout << "Design patterns give reusable solutions to common design problems.\n";
    cout << "Demo: Observer pattern\n\n";
    Subject s;
    DisplayA a; DisplayB b;
    s.attach(&a);
    s.attach(&b);
    s.setState(5);
    s.setState(9);
    return 0;
}
