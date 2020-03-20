#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
//program to rotate image
int main(){
    Mat imgOrg = imread("sample1.jpg");
    if(imgOrg.empty()){
        cout << "Fail to load image";
        cin.get();
        return -1;
    }
    imshow("Original", imgOrg);

    namedWindow("Rotated", CV_WINDOW_AUTOSIZE);
    int ang = 180;
    createTrackbar("Angle", "Rotated", &ang, 360);

    int centreY = imgOrg.rows / 2;
    int centreX = imgOrg.cols / 2;

    while(true){
        Mat matrotation = getRotationMatrix2D(Point(centreX, centreY), (ang - 180), 1);
        Mat rotatedImg;
        warpAffine(imgOrg, rotatedImg, matrotation, imgOrg.size());
        imshow("Rotated", rotatedImg);
        waitKey(30);
        if(waitKey(30) == 27){
            break;
        }
    }
    return 0;
}

//program to rotate and scale image
/*
int iAngle = 180;
int iScale = 50;
int iBorderMode = 0;
Mat imgOriginal;
int iImageCenterY = 0;
int iImageCenterX = 0;
const char *pzRotatedImage = "Rotated Image";

void CallbackForTrackBar(int, void *){
    Mat matRotation = getRotationMatrix2D(Point(iImageCenterX, iImageCenterY), (iAngle - 180), iScale / 50.0);

    // Rotate the image
    Mat imgRotated;
    warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size(), INTER_LINEAR, iBorderMode, Scalar());

    imshow(pzRotatedImage, imgRotated);
}

int main(int argc, char **argv){
    // Load the image
    imgOriginal = imread("sample1.jpg", 1);

    iImageCenterY = imgOriginal.rows / 2;
    iImageCenterX = imgOriginal.cols / 2;

    //show the original image
    const char *pzOriginalImage = "Original Image";
    namedWindow(pzOriginalImage, CV_WINDOW_AUTOSIZE);
    imshow(pzOriginalImage, imgOriginal);

    //create the "Rotated Image" window and 3 trackbars in it
    namedWindow(pzRotatedImage, CV_WINDOW_AUTOSIZE);
    createTrackbar("Angle", pzRotatedImage, &iAngle, 360, CallbackForTrackBar);
    createTrackbar("Scale", pzRotatedImage, &iScale, 100, CallbackForTrackBar);
    createTrackbar("Border Mode", pzRotatedImage, &iBorderMode, 5, CallbackForTrackBar);

    int iDummy = 0;

    CallbackForTrackBar(iDummy, &iDummy);

    waitKey(0);

    return 0;
}*/