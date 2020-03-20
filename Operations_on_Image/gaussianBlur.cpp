// gaussBlur.cpp
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("sample1.jpg");
    
    if(image.empty()){
        cout << "Could not load image" << endl;
        cin.get();
        return -1;
    }
    Mat blur3x3;
    GaussianBlur(image, blur3x3, Size(3, 3), 0);

    Mat blur5x5;
    GaussianBlur(image, blur5x5, Size(5, 5), 0);

    imshow("Original", image);
    imshow("3x3", blur3x3);
    imshow("5x5", blur5x5);
    waitKey(0);
    destroyAllWindows();
    return 0;
}