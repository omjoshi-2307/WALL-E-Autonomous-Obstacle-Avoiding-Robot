// OOPVC Practical 8.3: Cohen-Sutherland line clipping
// File: system24.cpp
// ALGORITHM:
// 1. Read line endpoints and clipping-window limits.
// 2. Calculate region codes, then accept, reject, or clip the line by finding boundary intersections.

// Cohen-Sutherland line clipping algorithm (graphics.h)
#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

const int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xmin = 150, ymin = 100, xmax = 450, ymax = 300;   // clipping window

int computeCode(double x, double y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= TOP;          // y grows downward on screen
    else if (y > ymax) code |= BOTTOM;
    return code;
}

bool cohenSutherland(double &x1, double &y1, double &x2, double &y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) { accept = true; break; }     // both inside
        else if (code1 & code2) break;                      // both outside same region
        else {
            double x, y;
            int out = code1 ? code1 : code2;
            if (out & TOP) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1); y = ymin;
            } else if (out & BOTTOM) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1); y = ymax;
            } else if (out & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1); x = xmax;
            } else {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1); x = xmin;
            }
            if (out == code1) { x1 = x; y1 = y; code1 = computeCode(x1, y1); }
            else              { x2 = x; y2 = y; code2 = computeCode(x2, y2); }
        }
    }
    return accept;
}

int main() {
    double x1, y1, x2, y2;
    cout << "Window: (150,100) to (450,300)\nEnter x1 y1 x2 y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(RED);
    line((int)x1, (int)y1, (int)x2, (int)y2);           // original line
    outtextxy(10, 10, (char*)"Red: original line, Green: clipped line");

    if (cohenSutherland(x1, y1, x2, y2)) {
        setcolor(GREEN);
        line((int)x1, (int)y1, (int)x2, (int)y2);
    } else {
        outtextxy(10, 30, (char*)"Line is completely outside the window");
    }

    getch();
    closegraph();
    return 0;
}
