// OOPVC Practical 8.2: Bresenham's line drawing algorithm
// File: system23.cpp
// ALGORITHM:
// 1. Read line endpoints and initialize the decision parameter.
// 2. Plot pixels and update the decision parameter until the endpoint is reached.

// Bresenham's line drawing algorithm (works for all slopes) (graphics.h)
#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

void bresenham(int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 <  dx) { err += dx; y1 += sy; }
    }
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    bresenham(x1, y1, x2, y2, WHITE);
    outtextxy(10, 10, (char*)"Line drawn using Bresenham's algorithm");

    getch();
    closegraph();
    return 0;
}
