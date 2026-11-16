// ============================================================================
// OOPVC LABORATORY PRACTICAL 1.3
// Dynamic memory allocation using new and delete
// File: system03.cpp
// ============================================================================
// ALGORITHM
// 1. Allocate an integer dynamically using new and assign a value.
// 2. Display the value and release the memory using delete.
// 3. Read the array size, dynamically allocate an array, and calculate its sum.
// 4. Release the array using delete[]; dynamically create and delete a Box object.
// ============================================================================

#include <iostream>
using namespace std;

class Box {
    int length;
public:
    Box(int l = 0) { length = l; cout << "Box created, length = " << length << endl; }
    ~Box() { cout << "Box destroyed, length = " << length << endl; }
};

int main() {
    // single variable
    int *p = new int;
    *p = 50;
    cout << "Value = " << *p << endl;
    delete p;

    // array
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    cout << "Sum = " << sum << endl;
    delete[] arr;

    // object
    Box *b = new Box(10);
    delete b;
    return 0;
}
