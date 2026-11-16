// OOPVC Practical 9.1: Basic concepts of digital image processing (OpenCV)
// File: system25.cpp
// ALGORITHM:
// 1. Load an image using OpenCV and verify it loaded.
// 2. Display the image and perform the basic image-processing demonstration.

// Basic concepts of digital image processing (OpenCV)
// An image = matrix of pixels. Gray image: 1 channel (0-255). Color image: 3 channels (B,G,R).
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    Mat img = imread("image.jpg");
    if (img.empty()) { cout << "Image not found!\n"; return 1; }

    cout << "Width    : " << img.cols << endl;
    cout << "Height   : " << img.rows << endl;
    cout << "Channels : " << img.channels() << endl;
    cout << "Total pixels: " << img.total() << endl;

    Vec3b pixel = img.at<Vec3b>(50, 50);              // pixel at row 50, col 50
    cout << "Pixel(50,50) B=" << (int)pixel[0] << " G=" << (int)pixel[1]
         << " R=" << (int)pixel[2] << endl;

    imshow("Original Image", img);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
