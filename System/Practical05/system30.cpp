// OOPVC Practical 10.3: Simple game: Ping Pong (OOP)
// File: system30.cpp
// ALGORITHM:
// 1. Initialize the game window, paddle, and ball.
// 2. Read controls, update positions, detect collisions, and refresh the game state.

// Simple Ping Pong game using OOP + graphics.h
// Player (left):  W = up, S = down      Q = quit
#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

class Paddle {
public:
    int x, y, w, h;
    Paddle(int x, int y) : x(x), y(y), w(10), h(80) {}
    void draw() {
        setcolor(WHITE); setfillstyle(SOLID_FILL, WHITE);
        bar(x, y, x + w, y + h);
    }
    void move(int d) {
        y += d;
        if (y < 0) y = 0;
        if (y + h > getmaxy()) y = getmaxy() - h;
    }
};

class Ball {
public:
    int x, y, dx, dy, r;
    Ball() : x(320), y(240), dx(5), dy(4), r(8) {}
    void draw() {
        setcolor(YELLOW); setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(x, y, r, r);
    }
    void reset() { x = getmaxx() / 2; y = getmaxy() / 2; dx = -dx; dy = 4; }
    void move() {
        x += dx; y += dy;
        if (y - r < 0 || y + r > getmaxy()) dy = -dy;
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    Paddle player(20, 200), computer(getmaxx() - 30, 200);
    Ball ball;
    int score1 = 0, score2 = 0;
    char buf[50];
    bool running = true;

    while (running) {
        cleardevice();
        line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
        sprintf(buf, "Player: %d    Computer: %d", score1, score2);
        outtextxy(getmaxx() / 2 - 100, 10, buf);

        if (kbhit()) {
            char c = getch();
            if (c == 'w' || c == 'W') player.move(-20);
            if (c == 's' || c == 'S') player.move(20);
            if (c == 'q' || c == 'Q') running = false;
        }

        // computer follows the ball
        if (ball.y < computer.y + computer.h / 2) computer.move(-4);
        else computer.move(4);

        ball.move();

        // paddle collision
        if (ball.x - ball.r <= player.x + player.w && ball.y >= player.y && ball.y <= player.y + player.h)
            ball.dx = abs(ball.dx);
        if (ball.x + ball.r >= computer.x && ball.y >= computer.y && ball.y <= computer.y + computer.h)
            ball.dx = -abs(ball.dx);

        // scoring
        if (ball.x < 0)            { score2++; ball.reset(); }
        if (ball.x > getmaxx())    { score1++; ball.reset(); }

        player.draw(); computer.draw(); ball.draw();
        delay(25);
    }
    closegraph();
    return 0;
}
