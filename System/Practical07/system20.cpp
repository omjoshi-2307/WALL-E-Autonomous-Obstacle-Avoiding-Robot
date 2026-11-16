// OOPVC Practical 7.2: 3D translation, rotation, scaling using matrices
// File: system20.cpp
// ALGORITHM:
// 1. Define the 3D object and the required transformation matrices.
// 2. Transform each vertex and display or draw the resulting object.

// 3D translation, rotation and scaling using 4x4 transformation matrices
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

void multiply(double a[4][4], double b[4][4], double c[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 4; k++) c[i][j] += a[i][k] * b[k][j];
        }
}

void identity(double m[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) m[i][j] = (i == j);
}

void transformPoint(double m[4][4], double v[4], double r[4]) {
    for (int i = 0; i < 4; i++) {
        r[i] = 0;
        for (int j = 0; j < 4; j++) r[i] += m[i][j] * v[j];
    }
}

void printMatrix(double m[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) cout << round(m[i][j] * 100) / 100 << "\t";
        cout << endl;
    }
}

int main() {
    // cube vertices (x, y, z, 1)
    double cube[8][4] = {{0,0,0,1},{1,0,0,1},{1,1,0,1},{0,1,0,1},
                         {0,0,1,1},{1,0,1,1},{1,1,1,1},{0,1,1,1}};
    double M[4][4], res[4];
    int ch;
    cout << "1.Translation  2.Scaling  3.Rotation(X)  4.Rotation(Y)  5.Rotation(Z)\nChoice: ";
    cin >> ch;
    identity(M);

    if (ch == 1) {
        double tx, ty, tz;
        cout << "Enter tx ty tz: "; cin >> tx >> ty >> tz;
        M[0][3] = tx; M[1][3] = ty; M[2][3] = tz;
    } else if (ch == 2) {
        double sx, sy, sz;
        cout << "Enter sx sy sz: "; cin >> sx >> sy >> sz;
        M[0][0] = sx; M[1][1] = sy; M[2][2] = sz;
    } else {
        double deg;
        cout << "Enter angle in degrees: "; cin >> deg;
        double a = deg * PI / 180;
        if (ch == 3) { M[1][1] = cos(a); M[1][2] = -sin(a); M[2][1] = sin(a); M[2][2] = cos(a); }
        if (ch == 4) { M[0][0] = cos(a); M[0][2] = sin(a); M[2][0] = -sin(a); M[2][2] = cos(a); }
        if (ch == 5) { M[0][0] = cos(a); M[0][1] = -sin(a); M[1][0] = sin(a); M[1][1] = cos(a); }
    }

    cout << "\nTransformation matrix:\n";
    printMatrix(M);

    cout << "\nVertex\tBefore\t\t\tAfter\n";
    for (int i = 0; i < 8; i++) {
        transformPoint(M, cube[i], res);
        cout << i + 1 << "\t(" << cube[i][0] << "," << cube[i][1] << "," << cube[i][2] << ")\t\t("
             << round(res[0] * 100) / 100 << "," << round(res[1] * 100) / 100 << ","
             << round(res[2] * 100) / 100 << ")\n";
    }
    return 0;
}
