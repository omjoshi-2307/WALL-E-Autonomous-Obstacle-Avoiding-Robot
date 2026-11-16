// OOPVC Practical 6.3: 2D reflection and shearing
// File: system18.cpp
// ALGORITHM:
// 1. Define triangle vertices and a matrix multiplication function.
// 2. Select reflection or shearing, transform vertices, and draw the result.

// 2D Reflection and Shearing using matrix multiplication (graphics.h)
#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

void multiply(double m[3][3], double pts[3][3], double res[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 3; k++) res[i][j] += m[i][k] * pts[k][j];
        }
}

int cx, cy;   // screen centre used as origin

void drawTriangle(double t[3][3], int color) {
    setcolor(color);
    for (int i = 0; i < 3; i++) {
        int j = (i + 1) % 3;
        line(cx + (int)t[0][i], cy - (int)t[1][i], cx + (int)t[0][j], cy - (int)t[1][j]);
    }
}

int main() {
    double tri[3][3] = {{50, 150, 100},
                        {50, 50, 150},
                        {1,  1,  1}};
    double res[3][3];
    int ch;
    cout << "1.Reflection about X  2.Reflection about Y  3.Shear in X  4.Shear in Y\nChoice: ";
    cin >> ch;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    cx = getmaxx() / 2; cy = getmaxy() / 2;
    setcolor(WHITE);
    line(0, cy, getmaxx(), cy);               // X axis
    line(cx, 0, cx, getmaxy());               // Y axis
    drawTriangle(tri, WHITE);

    double M[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    if (ch == 1)      M[1][1] = -1;           // reflect about X
    else if (ch == 2) M[0][0] = -1;           // reflect about Y
    else if (ch == 3) M[0][1] = 1.0;          // shear X, shx = 1
    else              M[1][0] = 1.0;          // shear Y, shy = 1

    multiply(M, tri, res);
    drawTriangle(res, YELLOW);
    outtextxy(10, 10, (char*)"White: Original, Yellow: Transformed");

    getch();
    closegraph();
    return 0;
}
