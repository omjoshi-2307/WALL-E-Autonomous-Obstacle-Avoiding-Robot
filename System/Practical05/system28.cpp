// OOPVC Practical 10.1: Animation of moving objects (OOP + graphics)
// File: system28.cpp
// ALGORITHM:
// 1. Initialize the graphics window and moving object.
// 2. Update object position, redraw animation frames, and handle movement boundaries.

// Animation of moving objects using OOP + graphics.h
#include <graphics.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

class MovingObject {
protected:
    int x, y, dx, dy, color;
public:
    MovingObject(int x, int y, int dx, int dy, int color)
        : x(x), y(y), dx(dx), dy(dy), color(color) {}
    virtual void draw() = 0;
    virtual void move() {
        x += dx; y += dy;
        if (x < 30 || x > getmaxx() - 30) dx = -dx;     // bounce on walls
        if (y < 30 || y > getmaxy() - 30) dy = -dy;
    }
    virtual ~MovingObject() {}
};

class Ball : public MovingObject {
public:
    Ball(int x, int y, int dx, int dy, int c) : MovingObject(x, y, dx, dy, c) {}
    void draw() override {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        fillellipse(x, y, 20, 20);
    }
};

class Box : public MovingObject {
public:
    Box(int x, int y, int dx, int dy, int c) : MovingObject(x, y, dx, dy, c) {}
    void draw() override {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        bar(x - 20, y - 20, x + 20, y + 20);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    MovingObject *objs[3];
    objs[0] = new Ball(100, 100, 4, 3, RED);
    objs[1] = new Box(300, 200, -5, 4, GREEN);
    objs[2] = new Ball(450, 350, 3, -5, YELLOW);

    while (!kbhit()) {                       // press any key to stop
        cleardevice();
        for (int i = 0; i < 3; i++) { objs[i]->draw(); objs[i]->move(); }
        outtextxy(10, 10, (char*)"Animation - press any key to exit");
        delay(20);
    }
    for (int i = 0; i < 3; i++) delete objs[i];
    getch();
    closegraph();
    return 0;
}
