// OOPVC Practical 5.3: Draw basic primitives: line, circle, rectangle
// File: system15.cpp
// ALGORITHM:
// 1. Initialize the graphics window and select drawing colors.
// 2. Draw basic primitives and fill a closed shape.

// Draw basic primitives: line, circle, rectangle (+ ellipse, arc, polygon)
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setcolor(RED);
    line(50, 50, 250, 50);
    outtextxy(50, 35, (char*)"Line");

    setcolor(GREEN);
    rectangle(50, 100, 200, 200);
    outtextxy(50, 85, (char*)"Rectangle");

    setcolor(YELLOW);
    circle(350, 150, 60);
    outtextxy(320, 85, (char*)"Circle");

    setcolor(CYAN);
    ellipse(520, 150, 0, 360, 70, 40);
    outtextxy(490, 85, (char*)"Ellipse");

    setcolor(WHITE);
    arc(150, 320, 0, 180, 50);
    outtextxy(120, 260, (char*)"Arc");

    int poly[] = {350, 380, 420, 260, 490, 380, 350, 380};
    setcolor(MAGENTA);
    drawpoly(4, poly);
    outtextxy(380, 245, (char*)"Triangle");

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(100, 150, GREEN);

    getch();
    closegraph();
    return 0;
}
