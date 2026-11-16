// OOPVC Practical 4.2: Factory and Singleton design patterns
// File: system11.cpp
// ALGORITHM:
// 1. Implement a Singleton instance accessor and a Shape factory.
// 2. Verify the singleton identity; create, draw, and delete factory-created shapes.

#include <iostream>
#include <string>
using namespace std;

// ================= Singleton =================
class Singleton {
    static Singleton *instance;
    Singleton() { cout << "Singleton instance created\n"; }
public:
    static Singleton* getInstance() {
        if (instance == nullptr) instance = new Singleton();
        return instance;
    }
    void show() { cout << "Only one object exists: " << this << endl; }
};
Singleton* Singleton::instance = nullptr;

// ================= Factory =================
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};
class Circle : public Shape {
public: void draw() override { cout << "Drawing Circle\n"; }
};
class Square : public Shape {
public: void draw() override { cout << "Drawing Square\n"; }
};
class Triangle : public Shape {
public: void draw() override { cout << "Drawing Triangle\n"; }
};

class ShapeFactory {
public:
    static Shape* createShape(string type) {
        if (type == "circle")   return new Circle();
        if (type == "square")   return new Square();
        if (type == "triangle") return new Triangle();
        return nullptr;
    }
};

int main() {
    cout << "--- Singleton ---\n";
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    s1->show(); s2->show();
    cout << (s1 == s2 ? "Both pointers are same\n" : "Different objects\n");

    cout << "\n--- Factory ---\n";
    string types[] = {"circle", "square", "triangle"};
    for (int i = 0; i < 3; i++) {
        Shape *sh = ShapeFactory::createShape(types[i]);
        if (sh) { sh->draw(); delete sh; }
    }
    return 0;
}
