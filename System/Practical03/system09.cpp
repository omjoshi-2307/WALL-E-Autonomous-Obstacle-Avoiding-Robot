// OOPVC Practical 3.3: Data storage and retrieval using file handling
// File: system09.cpp
// ALGORITHM:
// 1. Define a record structure and file functions for add, display, and search.
// 2. Use a menu to perform binary file operations until exit.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int roll;
    char name[30];
    float marks;
};

void addRecord() {
    Student s;
    cout << "Enter roll, name, marks: ";
    cin >> s.roll >> s.name >> s.marks;
    ofstream fout("students.dat", ios::binary | ios::app);
    fout.write((char*)&s, sizeof(s));
    fout.close();
    cout << "Record stored.\n";
}

void displayAll() {
    Student s;
    ifstream fin("students.dat", ios::binary);
    cout << "\nRoll\tName\tMarks\n";
    while (fin.read((char*)&s, sizeof(s)))
        cout << s.roll << "\t" << s.name << "\t" << s.marks << endl;
    fin.close();
}

void searchRecord() {
    int r; bool found = false;
    Student s;
    cout << "Enter roll to search: ";
    cin >> r;
    ifstream fin("students.dat", ios::binary);
    while (fin.read((char*)&s, sizeof(s))) {
        if (s.roll == r) {
            cout << "Found: " << s.name << ", Marks = " << s.marks << endl;
            found = true; break;
        }
    }
    fin.close();
    if (!found) cout << "Record not found.\n";
}

int main() {
    int ch;
    do {
        cout << "\n1.Add  2.Display All  3.Search  4.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: addRecord(); break;
            case 2: displayAll(); break;
            case 3: searchRecord(); break;
        }
    } while (ch != 4);
    return 0;
}
