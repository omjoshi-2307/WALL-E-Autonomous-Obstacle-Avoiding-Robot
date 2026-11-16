// ============================================================================
// OOPVC LABORATORY PRACTICAL 1.2
// Constructors and destructors
// File: system02.cpp
// ============================================================================
// ALGORITHM
// 1. Define a class with default, parameterized, and copy constructors.
// 2. Create objects using each constructor.
// 3. Display the initialized data of every object.
// 4. End the program and observe destructor calls.
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

class Demo {
    string name;
    int id;
public:
    Demo() {                              // default constructor
        name = "Unknown"; id = 0;
        cout << "Default constructor called\n";
    }
    Demo(string n, int i) {               // parameterized constructor
        name = n; id = i;
        cout << "Parameterized constructor called for " << name << endl;
    }
    Demo(const Demo &d) {                 // copy constructor
        name = d.name + "_copy"; id = d.id;
        cout << "Copy constructor called for " << name << endl;
    }
    void show() { cout << "ID: " << id << "  Name: " << name << endl; }
    ~Demo() {                             // destructor
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Demo d1;
    Demo d2("Object2", 2);
    Demo d3 = d2;
    d1.show(); d2.show(); d3.show();
    cout << "End of main\n";
    return 0;
}
