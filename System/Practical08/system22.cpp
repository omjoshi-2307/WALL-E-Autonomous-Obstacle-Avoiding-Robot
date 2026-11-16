// OOPVC Practical 8.1: Basic concepts of line drawing algorithms (DDA)
// File: system22.cpp
// ALGORITHM:
// 1. Read line endpoints and calculate dx, dy, and the step count.
// 2. Calculate increments and plot rounded points until the endpoint is reached.

// Basic concepts of line drawing algorithms: DDA algorithm (graphics.h)
// Line equation: y = m*x + c. Pixels are chosen step by step along the line.
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>
using namespace std;

void ddaLine(int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1, dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), color);
        x += xInc;
        y += yInc;
    }
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    ddaLine(x1, y1, x2, y2, YELLOW);
    outtextxy(10, 10, (char*)"Line drawn using DDA algorithm");

    getch();
    closegraph();
    return 0;
}
