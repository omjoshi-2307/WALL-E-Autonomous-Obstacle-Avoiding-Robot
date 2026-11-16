// ============================================================================
// OOPVC LABORATORY PRACTICAL 1.1
// Classes and objects
// File: system01.cpp
// ============================================================================
// ALGORITHM
// 1. Define a Student class with data members and member functions.
// 2. Create individual Student objects and assign their details.
// 3. Display the details of each object.
// 4. Create an array of Student objects, assign values, and display them using a loop.
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float marks;
public:
    void setData(string n, int r, float m) {
        name = n; roll = r; marks = m;
    }
    void display() {
        cout << "Roll: " << roll << "  Name: " << name << "  Marks: " << marks << endl;
    }
};

int main() {
    Student s1, s2;
    s1.setData("Amit", 1, 85.5);
    s2.setData("Neha", 2, 91.0);

    s1.display();
    s2.display();

    Student list[2];
    list[0].setData("Rahul", 3, 72.0);
    list[1].setData("Sneha", 4, 88.0);
    for (int i = 0; i < 2; i++) list[i].display();
    return 0;
}
