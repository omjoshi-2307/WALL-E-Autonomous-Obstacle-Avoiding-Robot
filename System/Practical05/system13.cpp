// OOPVC Practical 5.1: Basic concepts of visual computing and computer graphics
// File: system13.cpp
// ALGORITHM:
// 1. Initialize the graphics window and inspect screen dimensions.
// 2. Display coordinate axes, pixels, and colors.

// Basic concepts of visual computing and computer graphics:
// screen = grid of pixels, origin (0,0) at top-left, x to right, y downward.
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int maxX = getmaxx(), maxY = getmaxy();
    char buf[100];

    sprintf(buf, "Screen resolution: %d x %d pixels", maxX + 1, maxY + 1);
    outtextxy(20, 20, buf);
    outtextxy(20, 40, (char*)"Origin (0,0) is the top-left corner");

    // Axes
    setcolor(WHITE);
    line(0, 0, 200, 0);   outtextxy(205, 0, (char*)"X axis");
    line(0, 0, 0, 200);   outtextxy(5, 205, (char*)"Y axis");

    // Pixels (smallest unit of an image)
    for (int i = 0; i < 100; i++) putpixel(100 + i, 100, YELLOW);
    outtextxy(100, 110, (char*)"A row of pixels drawn with putpixel()");

    // Colors
    setfillstyle(SOLID_FILL, RED);   bar(100, 150, 150, 200);
    setfillstyle(SOLID_FILL, GREEN); bar(160, 150, 210, 200);
    setfillstyle(SOLID_FILL, BLUE);  bar(220, 150, 270, 200);
    outtextxy(100, 210, (char*)"RGB colors");

    getch();
    closegraph();
    return 0;
}
