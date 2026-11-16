// ============================================================================
// OOPVC LABORATORY PRACTICAL 2.1
// Single, multilevel and hierarchical inheritance
// File: system04.cpp
// ============================================================================
// ALGORITHM
// 1. Define classes to demonstrate single, multilevel, and hierarchical inheritance.
// 2. Create derived-class objects and access inherited members.
// 3. Call the functions belonging to each inheritance level.
// 4. Calculate and display the rectangle and triangle areas.
// ============================================================================

#include <iostream>
using namespace std;

// ---- Single inheritance ----
class Person {
public:
    string name;
    void getName(string n) { name = n; }
};
class Student : public Person {
public:
    int roll;
    void show() { cout << "Student: " << name << ", Roll: " << roll << endl; }
};

// ---- Multilevel inheritance ----
class Animal {
public:
    void eat() { cout << "Animal eats\n"; }
};
class Mammal : public Animal {
public:
    void walk() { cout << "Mammal walks\n"; }
};
class Dog : public Mammal {
public:
    void bark() { cout << "Dog barks\n"; }
};

// ---- Hierarchical inheritance ----
class Shape {
public:
    float a, b;
    void setValues(float x, float y) { a = x; b = y; }
};
class Rectangle : public Shape {
public:
    float area() { return a * b; }
};
class Triangle : public Shape {
public:
    float area() { return 0.5 * a * b; }
};

int main() {
    cout << "--- Single Inheritance ---\n";
    Student s; s.getName("Amit"); s.roll = 101; s.show();

    cout << "--- Multilevel Inheritance ---\n";
    Dog d; d.eat(); d.walk(); d.bark();

    cout << "--- Hierarchical Inheritance ---\n";
    Rectangle r; r.setValues(4, 5);
    Triangle t;  t.setValues(4, 5);
    cout << "Rectangle area = " << r.area() << endl;
    cout << "Triangle area  = " << t.area() << endl;
    return 0;
}
