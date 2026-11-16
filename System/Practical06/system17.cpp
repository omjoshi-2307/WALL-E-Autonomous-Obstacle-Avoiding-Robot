// OOPVC Practical 6.2: 2D translation, rotation, scaling using matrix multiplication
// File: system17.cpp
// ALGORITHM:
// 1. Define triangle vertices and a matrix multiplication function.
// 2. Select translation, rotation, or scaling, transform vertices, and draw both triangles.

// 2D Translation, Rotation, Scaling using matrix multiplication (graphics.h)
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.14159265358979;

void multiply(double m[3][3], double pts[3][3], double res[3][3]) {
    // pts: 3 columns = 3 vertices, rows = x, y, 1
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 3; k++) res[i][j] += m[i][k] * pts[k][j];
        }
}

void drawTriangle(double t[3][3], int color) {
    setcolor(color);
    for (int i = 0; i < 3; i++) {
        int j = (i + 1) % 3;
        line((int)t[0][i], (int)t[1][i], (int)t[0][j], (int)t[1][j]);
    }
}

int main() {
    double tri[3][3] = {{100, 200, 150},    // x coordinates
                        {100, 100, 40},     // y coordinates
                        {1,   1,   1}};
    double res[3][3];
    int ch;
    cout << "1.Translation  2.Rotation  3.Scaling\nEnter choice: ";
    cin >> ch;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    drawTriangle(tri, WHITE);                 // original

    if (ch == 1) {
        double tx = 150, ty = 100;
        double T[3][3] = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};
        multiply(T, tri, res);
        drawTriangle(res, YELLOW);
        outtextxy(10, 10, (char*)"White: Original, Yellow: Translated");
    } else if (ch == 2) {
        double a = 45 * PI / 180;
        double px = 100, py = 100;            // rotate about point (100,100)
        double R[3][3] = {{cos(a), -sin(a), px - px * cos(a) + py * sin(a)},
                          {sin(a),  cos(a), py - px * sin(a) - py * cos(a)},
                          {0, 0, 1}};
        multiply(R, tri, res);
        drawTriangle(res, GREEN);
        outtextxy(10, 10, (char*)"White: Original, Green: Rotated 45 deg");
    } else {
        double sx = 2, sy = 2;
        double S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
        multiply(S, tri, res);
        drawTriangle(res, CYAN);
        outtextxy(10, 10, (char*)"White: Original, Cyan: Scaled (2x)");
    }
    getch();
    closegraph();
    return 0;
}
