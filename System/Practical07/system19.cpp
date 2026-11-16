// OOPVC Practical 7.1: Basic concepts of 3D geometric transformations
// File: system19.cpp
// ALGORITHM:
// 1. Represent a 3D point with homogeneous coordinates.
// 2. Apply 4x4 translation, scaling, and rotation matrices; display transformed coordinates.

// Basic concepts of 3D transformations (console demo, 4x4 homogeneous matrices)
// Point P(x,y,z) is written as [x y z 1]^T and P' = M * P
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

void apply(double m[4][4], double p[4], double r[4]) {
    for (int i = 0; i < 4; i++) {
        r[i] = 0;
        for (int j = 0; j < 4; j++) r[i] += m[i][j] * p[j];
    }
}

void show(const char *name, double r[4]) {
    cout << name << " -> (" << round(r[0] * 100) / 100 << ", "
         << round(r[1] * 100) / 100 << ", " << round(r[2] * 100) / 100 << ")\n";
}

int main() {
    double p[4] = {1, 2, 3, 1}, r[4];
    cout << "Original point: (1, 2, 3)\n\n";

    double T[4][4] = {{1,0,0,5}, {0,1,0,2}, {0,0,1,1}, {0,0,0,1}};
    apply(T, p, r); show("Translation (5,2,1)", r);

    double S[4][4] = {{2,0,0,0}, {0,2,0,0}, {0,0,2,0}, {0,0,0,1}};
    apply(S, p, r); show("Scaling (2,2,2)", r);

    double a = 90 * PI / 180;
    double Rx[4][4] = {{1,0,0,0}, {0,cos(a),-sin(a),0}, {0,sin(a),cos(a),0}, {0,0,0,1}};
    apply(Rx, p, r); show("Rotation about X (90)", r);

    double Ry[4][4] = {{cos(a),0,sin(a),0}, {0,1,0,0}, {-sin(a),0,cos(a),0}, {0,0,0,1}};
    apply(Ry, p, r); show("Rotation about Y (90)", r);

    double Rz[4][4] = {{cos(a),-sin(a),0,0}, {sin(a),cos(a),0,0}, {0,0,1,0}, {0,0,0,1}};
    apply(Rz, p, r); show("Rotation about Z (90)", r);
    return 0;
}
