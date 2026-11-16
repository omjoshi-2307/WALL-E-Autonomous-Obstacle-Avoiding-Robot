// OOPVC Practical 5.2: Initialize a graphics window (graphics.h)
// File: system14.cpp
// ALGORITHM:
// 1. Initialize the graphics driver and check the result.
// 2. Set screen properties, display text, wait for input, and close graphics.

// Initialize a graphics window using graphics.h
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");          // open graphics window

    int err = graphresult();
    if (err != grOk) {
        return 1;
    }

    setbkcolor(BLUE);
    cleardevice();
    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(100, 150, (char*)"Graphics Window Initialized");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(100, 200, (char*)"Press any key to close...");

    getch();
    closegraph();                             // close graphics window
    return 0;
}
