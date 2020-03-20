//program to load an image

#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
	//loading an image
    Mat img = imread("guitar.jpg");
    //create image with set of values of BGR
    //Mat img(600, 800, CV_8UC3, Scalar(100,100,30));
    if(img.empty()){
        cout << "Could not load image" << endl;
        cin.get();
        return -1;
    }
    //to invert image
    //bitwise_not(img,img);
    
    string windowName = "Guitar";
    
    namedWindow(windowName);
    imshow(windowName, img);
    waitKey(0);
    destroyWindow(windowName);
    return 0;
}