// OOPVC Practical 3.2: File operations: creation, reading, writing
// File: system08.cpp
// ALGORITHM:
// 1. Create and write to a file, then append additional data.
// 2. Read the file line by line and display its contents.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 1. Create and write
    ofstream fout("demo.txt");
    if (!fout) { cout << "File creation failed\n"; return 1; }
    fout << "Hello, this is the first line.\n";
    fout << "File handling in C++.\n";
    fout.close();
    cout << "File created and written.\n";

    // 2. Append
    ofstream fapp("demo.txt", ios::app);
    fapp << "This line is appended.\n";
    fapp.close();

    // 3. Read
    ifstream fin("demo.txt");
    string line;
    cout << "\nFile contents:\n";
    while (getline(fin, line)) cout << line << endl;
    fin.close();
    return 0;
}
