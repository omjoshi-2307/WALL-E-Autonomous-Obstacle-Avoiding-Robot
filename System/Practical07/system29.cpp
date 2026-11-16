// OOPVC Practical 10.2: Interactive 3D graphics application
// File: system29.cpp
// ALGORITHM:
// 1. Initialize the interactive 3D scene and define its object.
// 2. Read interaction input, transform/project vertices, and redraw until exit.

// Interactive 3D graphics: rotating / scaling / moving wireframe cube (graphics.h)
// Keys: A/D = rotate Y, W/S = rotate X, +/- = scale, Arrow keys = move, Q = quit
#include <graphics.h>
#include <conio.h>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

class Cube3D {
    double v[8][3];
    int edges[12][2];
public:
    double angX, angY, scale;
    int cx, cy;

    Cube3D() {
        double init[8][3] = {{-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},
                             {-1,-1, 1},{1,-1, 1},{1,1, 1},{-1,1, 1}};
        int e[12][2] = {{0,1},{1,2},{2,3},{3,0},{4,5},{5,6},{6,7},{7,4},{0,4},{1,5},{2,6},{3,7}};
        for (int i = 0; i < 8; i++) for (int j = 0; j < 3; j++) v[i][j] = init[i][j];
        for (int i = 0; i < 12; i++) for (int j = 0; j < 2; j++) edges[i][j] = e[i][j];
        angX = 20; angY = 30; scale = 80; cx = 320; cy = 240;
    }

    void project(int i, int &sx, int &sy) {
        double ax = angX * PI / 180, ay = angY * PI / 180;
        double x = v[i][0], y = v[i][1], z = v[i][2];
        double x1 = x * cos(ay) + z * sin(ay);               // rotate Y
        double z1 = -x * sin(ay) + z * cos(ay);
        double y1 = y * cos(ax) - z1 * sin(ax);              // rotate X
        double z2 = y * sin(ax) + z1 * cos(ax);
        double d = 5.0;                                      // perspective
        double f = d / (d + z2);
        sx = cx + (int)(x1 * scale * f);
        sy = cy - (int)(y1 * scale * f);
    }

    void draw() {
        setcolor(YELLOW);
        for (int i = 0; i < 12; i++) {
            int x1, y1, x2, y2;
            project(edges[i][0], x1, y1);
            project(edges[i][1], x2, y2);
            line(x1, y1, x2, y2);
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    Cube3D cube;
    int ch;
    do {
        cleardevice();
        outtextxy(10, 10, (char*)"A/D: rotate Y   W/S: rotate X   +/-: scale   Arrows: move   Q: quit");
        cube.draw();
        ch = getch();
        if (ch == 'a' || ch == 'A') cube.angY -= 5;
        if (ch == 'd' || ch == 'D') cube.angY += 5;
        if (ch == 'w' || ch == 'W') cube.angX -= 5;
        if (ch == 's' || ch == 'S') cube.angX += 5;
        if (ch == '+') cube.scale += 5;
        if (ch == '-' && cube.scale > 10) cube.scale -= 5;
        if (ch == 0 || ch == 224) {                       // arrow keys
            int k = getch();
            if (k == 72 || k == 'H') cube.cy -= 10;      // up
            if (k == 80 || k == 'P') cube.cy += 10;      // down
            if (k == 75 || k == 'K') cube.cx -= 10;      // left
            if (k == 77 || k == 'M') cube.cx += 10;      // right
        }
    } while (ch != 'q' && ch != 'Q');
    closegraph();
    return 0;
}
