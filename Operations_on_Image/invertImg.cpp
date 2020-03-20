//program to invert an image

//#include "stdafx.h"
#include <opencv2/opencv.hpp>
//#include <highgui.h>

int main(){
    //display the original image
    IplImage *img = cvLoadImage("guitar.jpg");
    cvNamedWindow("MyWindow");
    cvShowImage("MyWindow", img);

    //invert and display the inverted image
    cvNot(img, img);
    cvNamedWindow("Inverted");
    cvShowImage("Inverted", img);

    cvWaitKey(0);

    //cleaning up
    cvDestroyWindow("MyWindow");
    cvDestroyWindow("Inverted");
    cvReleaseImage(&img);

    return 0;
}