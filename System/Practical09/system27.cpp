// OOPVC Practical 9.3: Image blurring (OpenCV)
// File: system27.cpp
// ALGORITHM:
// 1. Load the image and apply a blur operation.
// 2. Display the original and blurred images.

// Image blurring using OpenCV
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    Mat img = imread("image.jpg");
    if (img.empty()) { cout << "Image not found!\n"; return 1; }

    Mat avg, gauss, med;
    blur(img, avg, Size(7, 7));                 // average (box) blur
    GaussianBlur(img, gauss, Size(7, 7), 0);    // Gaussian blur
    medianBlur(img, med, 7);                    // median blur

    imshow("Original", img);
    imshow("Average Blur", avg);
    imshow("Gaussian Blur", gauss);
    imshow("Median Blur", med);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
