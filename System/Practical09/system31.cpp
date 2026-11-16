// OOPVC Practical 10.4: Image filtering application (OpenCV)
// File: system31.cpp
// ALGORITHM:
// 1. Load the image and verify it is available.
// 2. Apply the selected image filter and display the filtered result.

// Image filtering application using OpenCV (menu driven)
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class ImageFilter {
    Mat original, result;
public:
    bool load(string path) {
        original = imread(path);
        return !original.empty();
    }
    void grayscale() { cvtColor(original, result, COLOR_BGR2GRAY); }
    void blurFilter() { GaussianBlur(original, result, Size(9, 9), 0); }
    void sharpen() {
        Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
        filter2D(original, result, -1, kernel);
    }
    void edges() {
        Mat gray;
        cvtColor(original, gray, COLOR_BGR2GRAY);
        Canny(gray, result, 100, 200);
    }
    void sepia() {
        Mat kernel = (Mat_<float>(3, 3) <<
            0.131, 0.534, 0.272,
            0.168, 0.686, 0.349,
            0.189, 0.769, 0.393);
        transform(original, result, kernel);
    }
    void negative() { bitwise_not(original, result); }
    void show() {
        imshow("Original", original);
        imshow("Filtered", result);
        waitKey(0);
        destroyAllWindows();
    }
    void save() { imwrite("filtered_output.jpg", result); cout << "Saved as filtered_output.jpg\n"; }
};

int main() {
    ImageFilter f;
    if (!f.load("image.jpg")) { cout << "Image not found!\n"; return 1; }
    int ch;
    do {
        cout << "\n1.Grayscale 2.Blur 3.Sharpen 4.Edge Detection 5.Sepia 6.Negative 7.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: f.grayscale(); break;
            case 2: f.blurFilter(); break;
            case 3: f.sharpen(); break;
            case 4: f.edges(); break;
            case 5: f.sepia(); break;
            case 6: f.negative(); break;
            default: continue;
        }
        if (ch >= 1 && ch <= 6) { f.show(); f.save(); }
    } while (ch != 7);
    return 0;
}
