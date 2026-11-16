// OOPVC Practical 2.3: Runtime polymorphism using virtual functions / overriding
// File: system06.cpp
// ALGORITHM:
// 1. Create an abstract base class and derived shape classes.
// 2. Create derived objects dynamically, call overridden functions through base pointers, then delete them.

#include <iostream>
using namespace std;

class Shape {                         // abstract class
public:
    virtual void draw() = 0;          // pure virtual function
    virtual double area() = 0;
    virtual ~Shape() { cout << "Shape destroyed\n"; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) { this->r = r; }
    void draw() override { cout << "Drawing Circle\n"; }
    double area() override { return 3.14159 * r * r; }
};

class Rectangle : public Shape {
    double l, b;
public:
    Rectangle(double l, double b) { this->l = l; this->b = b; }
    void draw() override { cout << "Drawing Rectangle\n"; }
    double area() override { return l * b; }
};

int main() {
    Shape *shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area = " << shapes[i]->area() << endl;
    }
    for (int i = 0; i < 2; i++) delete shapes[i];
    return 0;
}
