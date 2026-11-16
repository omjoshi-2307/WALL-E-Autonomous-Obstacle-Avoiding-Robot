// OOPVC Practical 6.1: Basic concepts of 2D geometric transformations
// File: system16.cpp
// ALGORITHM:
// 1. Represent a 2D point in homogeneous coordinates.
// 2. Apply translation, scaling, rotation, reflection, and shear matrices; display results.

// Basic concepts of 2D transformations (console demo with homogeneous coordinates)
// Point P(x, y) is written as [x y 1]^T, and new P' = M * P
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

void multiply(double m[3][3], double p[3], double r[3]) {
    for (int i = 0; i < 3; i++) {
        r[i] = 0;
        for (int j = 0; j < 3; j++) r[i] += m[i][j] * p[j];
    }
}

int main() {
    double p[3] = {4, 3, 1}, r[3];
    cout << "Original point: (" << p[0] << ", " << p[1] << ")\n\n";

    // Translation (tx=2, ty=5)
    double T[3][3] = {{1, 0, 2}, {0, 1, 5}, {0, 0, 1}};
    multiply(T, p, r);
    cout << "Translation (2,5)   -> (" << r[0] << ", " << r[1] << ")\n";

    // Scaling (sx=2, sy=3)
    double S[3][3] = {{2, 0, 0}, {0, 3, 0}, {0, 0, 1}};
    multiply(S, p, r);
    cout << "Scaling (2,3)       -> (" << r[0] << ", " << r[1] << ")\n";

    // Rotation by 90 degrees
    double a = 90 * PI / 180;
    double R[3][3] = {{cos(a), -sin(a), 0}, {sin(a), cos(a), 0}, {0, 0, 1}};
    multiply(R, p, r);
    cout << "Rotation 90 deg     -> (" << round(r[0]) << ", " << round(r[1]) << ")\n";

    // Reflection about X axis
    double RX[3][3] = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
    multiply(RX, p, r);
    cout << "Reflection about X  -> (" << r[0] << ", " << r[1] << ")\n";

    // Shearing in X (shx = 2)
    double SH[3][3] = {{1, 2, 0}, {0, 1, 0}, {0, 0, 1}};
    multiply(SH, p, r);
    cout << "Shear X (shx=2)     -> (" << r[0] << ", " << r[1] << ")\n";
    return 0;
}
