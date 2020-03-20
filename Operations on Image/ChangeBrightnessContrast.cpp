//change brightness and contrast of an image using trackbar

#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;


//using callback function
Mat img;

void changeBright(int s1, void *data){
    Mat dst;
    int s2 = *static_cast<int*>(data);
    int iB = s1 - 50;
    double iC = s2 / 50.0;
    cout << "Brightness: " << iB << " " << iC << endl;
    img.convertTo(dst, -1, iC, iB);

    imshow("Img", dst);
}

void changeContr(int s2, void *data){
    Mat dst;
    int s1 = *static_cast<int*>(data);
    int iB = s1 - 50;
    double iC = s2 / 50.0;
    cout << "Contrast: " << iB << " " << iC << endl;
    img.convertTo(dst, -1, iC, iB);
    imshow("Img", dst);
}

int main(){
    img = imread("sample1.jpg");
    if(img.empty()){
        cout << "Could not load image" << endl;
        cin.get();
        return -1;
    }
    namedWindow("Img",1);
    int s1 = 50;
    int s2 = 50;

    createTrackbar("Brightness", "Img", &s1, 100, changeBright, &s2);

    createTrackbar("Contrast", "Img", &s2, 100, changeContr, &s1);

    imshow("Img", img);
    waitKey(0);
    return 0;
}

//without using callback function
/*
int main(){
    Mat img = imread("sample1.jpg");
    if(img.empty()){
        cout << "Could not load image" << endl;
        cin.get();
        return -1;
    }
    namedWindow("Img",1);
    int s1 = 50;
    createTrackbar("Brightness", "Img", &s1, 100);

    int s2 = 50;
    createTrackbar("Contrast", "Img", &s2, 100);

    while(true){
        Mat out;
        int iBright = s1 - 50;
        double iCont = s2 / 50.0;
        img.convertTo(out, -1, iCont, iBright);
        imshow("Img",out);
        waitKey(50);
        if(waitKey(50) == 27){
            break;
        }
    }
}*/
    //return 0;
//}