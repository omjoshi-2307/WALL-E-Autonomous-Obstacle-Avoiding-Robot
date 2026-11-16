// OOPVC Practical 3.1: Exception handling using try, throw, catch
// File: system07.cpp
// ALGORITHM:
// 1. Read input and call functions that can throw exceptions.
// 2. Handle standard, custom, and other exceptions using try-catch blocks.

#include <iostream>
#include <stdexcept>
using namespace std;

class NegativeNumberException {
public:
    string msg;
    NegativeNumberException(string m) : msg(m) {}
};

double divide(int a, int b) {
    if (b == 0) throw runtime_error("Division by zero is not allowed");
    return (double)a / b;
}

void checkAge(int age) {
    if (age < 0) throw NegativeNumberException("Age cannot be negative");
    cout << "Age = " << age << endl;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    try {
        cout << "Result = " << divide(a, b) << endl;
    } catch (runtime_error &e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    try {
        checkAge(-5);
    } catch (NegativeNumberException &e) {
        cout << "Custom exception: " << e.msg << endl;
    }

    try {
        throw 10;
    } catch (int x) {
        cout << "Integer exception caught: " << x << endl;
    } catch (...) {
        cout << "Unknown exception\n";
    }
    cout << "Program continues normally\n";
    return 0;
}
