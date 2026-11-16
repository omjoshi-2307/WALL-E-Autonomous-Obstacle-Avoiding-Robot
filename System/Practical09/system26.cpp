// OOPVC Practical 9.2: Grayscale conversion and thresholding (OpenCV)
// File: system26.cpp
// ALGORITHM:
// 1. Load the image and convert it to grayscale.
// 2. Apply thresholding and display the original, grayscale, and binary images.

// Color image -> grayscale, then thresholding (OpenCV)
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    Mat img = imread("image.jpg");
    if (img.empty()) { cout << "Image not found!\n"; return 1; }

    Mat gray, binary, binaryInv, otsu;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    threshold(gray, binary,    127, 255, THRESH_BINARY);
    threshold(gray, binaryInv, 127, 255, THRESH_BINARY_INV);
    threshold(gray, otsu,        0, 255, THRESH_BINARY | THRESH_OTSU);

    imshow("Original", img);
    imshow("Grayscale", gray);
    imshow("Threshold (binary, T=127)", binary);
    imshow("Threshold (inverse)", binaryInv);
    imshow("Threshold (Otsu)", otsu);

    imwrite("gray.jpg", gray);
    imwrite("binary.jpg", binary);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
