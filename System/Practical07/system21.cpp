// OOPVC Practical 7.3: Visualize 3D objects after transformations
// File: system21.cpp
// ALGORITHM:
// 1. Initialize a graphics scene and define a 3D object.
// 2. Transform and project its vertices, then draw the transformed object.

// Visualize a 3D cube after applying geometric transformations (graphics.h)
// 3D -> 2D using oblique (cabinet) projection
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.14159265358979;

struct Point3D { double x, y, z; };

Point3D cube[8] = {{-50,-50,-50},{50,-50,-50},{50,50,-50},{-50,50,-50},
                   {-50,-50, 50},{50,-50, 50},{50,50, 50},{-50,50, 50}};
int edges[12][2] = {{0,1},{1,2},{2,3},{3,0},{4,5},{5,6},{6,7},{7,4},{0,4},{1,5},{2,6},{3,7}};

Point3D translate(Point3D p, double tx, double ty, double tz) { return {p.x + tx, p.y + ty, p.z + tz}; }
Point3D scale(Point3D p, double sx, double sy, double sz)     { return {p.x * sx, p.y * sy, p.z * sz}; }
Point3D rotateY(Point3D p, double deg) {
    double a = deg * PI / 180;
    return {p.x * cos(a) + p.z * sin(a), p.y, -p.x * sin(a) + p.z * cos(a)};
}
Point3D rotateX(Point3D p, double deg) {
    double a = deg * PI / 180;
    return {p.x, p.y * cos(a) - p.z * sin(a), p.y * sin(a) + p.z * cos(a)};
}

void project(Point3D p, int ox, int oy, int &sx, int &sy) {
    sx = ox + (int)(p.x - 0.5 * p.z * cos(PI / 4));
    sy = oy - (int)(p.y - 0.5 * p.z * sin(PI / 4));
}

void drawCube(Point3D v[8], int ox, int oy, int color) {
    setcolor(color);
    for (int i = 0; i < 12; i++) {
        int x1, y1, x2, y2;
        project(v[edges[i][0]], ox, oy, x1, y1);
        project(v[edges[i][1]], ox, oy, x2, y2);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    Point3D t[8];

    drawCube(cube, 120, 120, WHITE);
    outtextxy(70, 200, (char*)"Original");

    for (int i = 0; i < 8; i++) t[i] = translate(cube[i], 60, -30, 0);
    drawCube(t, 320, 120, YELLOW);
    outtextxy(270, 200, (char*)"Translated");

    for (int i = 0; i < 8; i++) t[i] = scale(cube[i], 1.5, 1.0, 1.0);
    drawCube(t, 520, 120, CYAN);
    outtextxy(470, 200, (char*)"Scaled (1.5,1,1)");

    for (int i = 0; i < 8; i++) t[i] = rotateY(cube[i], 40);
    drawCube(t, 170, 340, GREEN);
    outtextxy(120, 420, (char*)"Rotated about Y");

    for (int i = 0; i < 8; i++) t[i] = rotateX(cube[i], 40);
    drawCube(t, 420, 340, MAGENTA);
    outtextxy(370, 420, (char*)"Rotated about X");

    getch();
    closegraph();
    return 0;
}
