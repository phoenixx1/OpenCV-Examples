// homoSmooth.cpp
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("sample.jpg");
    
    if(image.empty()){
        cout << "Could not load image" << endl;
        cin.get();
        return -1;
    }
    Mat blur3x3;
    blur(image, blur3x3, Size(3, 3));

    Mat blur5x5;
    blur(image, blur5x5, Size(5, 5));

    imshow("Original", image);
    imshow("3x3", blur3x3);
    imshow("5x5", blur5x5);
    waitKey(0);
    destroyAllWindows();
    return 0;
}