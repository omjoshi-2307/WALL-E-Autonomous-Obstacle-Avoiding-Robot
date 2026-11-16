// OOPVC Practical 2.2: Compile-time and runtime polymorphism
// File: system05.cpp
// ALGORITHM:
// 1. Define overloaded functions/operators and virtual functions.
// 2. Call overloaded members and demonstrate runtime dispatch through a base pointer.

#include <iostream>
using namespace std;

// ---------- Compile-time polymorphism ----------
class Calc {
public:
    int add(int a, int b)          { return a + b; }        // function overloading
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c)   { return a + b + c; }
};

class Complex {                                             // operator overloading
    int re, im;
public:
    Complex(int r = 0, int i = 0) { re = r; im = i; }
    Complex operator+(Complex c)  { return Complex(re + c.re, im + c.im); }
    void show() { cout << re << " + " << im << "i\n"; }
};

// ---------- Runtime polymorphism ----------
class Base {
public:
    virtual void display() { cout << "Base class display\n"; }
    virtual ~Base() {}
};
class Derived : public Base {
public:
    void display() override { cout << "Derived class display\n"; }
};

int main() {
    cout << "=== Compile-time polymorphism ===\n";
    Calc c;
    cout << c.add(2, 3) << endl;
    cout << c.add(2.5, 3.5) << endl;
    cout << c.add(1, 2, 3) << endl;
    Complex c1(2, 3), c2(4, 5), c3;
    c3 = c1 + c2;
    c3.show();

    cout << "=== Runtime polymorphism ===\n";
    Base *ptr;
    Base b; Derived d;
    ptr = &b; ptr->display();
    ptr = &d; ptr->display();
    return 0;
}
