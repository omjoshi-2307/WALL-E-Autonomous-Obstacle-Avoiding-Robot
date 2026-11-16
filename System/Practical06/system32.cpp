// OOPVC Practical 10.5: 2D shape drawing and transformation visualizer
// File: system32.cpp
// ALGORITHM:
// 1. Define a 2D shape and its transformation functions.
// 2. Read the selected transformation, calculate new coordinates, and draw original and transformed shapes.

// Drawing 2D shapes and visualizing geometric transformations (OOP + graphics.h)
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.14159265358979;

class Shape2D {
public:
    int n;                    // number of vertices
    double x[10], y[10];
    Shape2D(int sides = 0) : n(sides) {}

    void draw(int color) {
        setcolor(color);
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            line((int)x[i], (int)y[i], (int)x[j], (int)y[j]);
        }
    }
    void translate(double tx, double ty) {
        for (int i = 0; i < n; i++) { x[i] += tx; y[i] += ty; }
    }
    void scale(double sx, double sy) {                 // about centroid
        double cx = 0, cy = 0;
        for (int i = 0; i < n; i++) { cx += x[i]; cy += y[i]; }
        cx /= n; cy /= n;
        for (int i = 0; i < n; i++) { x[i] = cx + (x[i] - cx) * sx; y[i] = cy + (y[i] - cy) * sy; }
    }
    void rotate(double deg) {                          // about centroid
        double a = deg * PI / 180, cx = 0, cy = 0;
        for (int i = 0; i < n; i++) { cx += x[i]; cy += y[i]; }
        cx /= n; cy /= n;
        for (int i = 0; i < n; i++) {
            double dx = x[i] - cx, dy = y[i] - cy;
            x[i] = cx + dx * cos(a) - dy * sin(a);
            y[i] = cy + dx * sin(a) + dy * cos(a);
        }
    }
    void reflectX(double axisY) { for (int i = 0; i < n; i++) y[i] = 2 * axisY - y[i]; }
    void shearX(double sh)      { for (int i = 0; i < n; i++) x[i] += sh * y[i]; }
};

Shape2D makeRect(double l, double t, double w, double h) {
    Shape2D s(4);
    s.x[0] = l;     s.y[0] = t;
    s.x[1] = l + w; s.y[1] = t;
    s.x[2] = l + w; s.y[2] = t + h;
    s.x[3] = l;     s.y[3] = t + h;
    return s;
}
Shape2D makeTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    Shape2D s(3);
    s.x[0] = x1; s.y[0] = y1; s.x[1] = x2; s.y[1] = y2; s.x[2] = x3; s.y[2] = y3;
    return s;
}

int main() {
    int shapeCh, trCh;
    while (true) {
        cout << "\nShape: 1.Rectangle 2.Triangle 0.Exit : ";
        cin >> shapeCh;
        if (shapeCh == 0) break;
        cout << "Transformation: 1.Translate 2.Scale 3.Rotate 4.Reflect 5.Shear : ";
        cin >> trCh;

        Shape2D s;
        if (shapeCh == 1) s = makeRect(100, 150, 100, 60);
        else              s = makeTriangle(100, 200, 200, 200, 150, 120);
        Shape2D orig = s;

        switch (trCh) {
            case 1: s.translate(150, 80); break;
            case 2: s.scale(1.8, 1.8); break;
            case 3: s.rotate(45); break;
            case 4: s.reflectX(240); break;
            case 5: s.shearX(0.7); break;
        }

        int gd = DETECT, gm;
        initgraph(&gd, &gm, (char*)"");
        line(0, 240, getmaxx(), 240);                  // reference line y = 240
        orig.draw(WHITE);
        s.draw(YELLOW);
        outtextxy(10, 10, (char*)"White: Original   Yellow: Transformed   (press a key)");
        getch();
        closegraph();
    }
    return 0;
}
