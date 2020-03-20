//detect mouse events occuring over an image

#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//simple mouse events

void mouseEvent(int event, int x, int y, int flags, void *userdata){
    if(event == EVENT_LBUTTONDOWN){
        cout << "Left: " << x << " " << y << endl;
    }else if(event == EVENT_RBUTTONDOWN){
        cout << "Right: " << x << " " << y << endl;
    }else if(event == EVENT_MBUTTONDOWN){
        cout << "Mid: " << x << " " << y << endl;
    }else if(event == EVENT_MOUSEMOVE){
        cout << "Loc: " << x << " " << y << endl;
    }
}
/*
//mouse event for combination with keys

void mouseEvent(int event, int x, int y, int flags, void *userdata){
    if(flags == (EVENT_FLAG_CTRLKEY + EVENT_FLAG_LBUTTON)){
        cout << "Left: " << x << " " << y << endl;
    }else if(flags == (EVENT_FLAG_ALTKEY + EVENT_FLAG_RBUTTON)){
        cout << "Right: " << x << " " << y << endl;
    }else if(event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_SHIFTKEY){
        cout << "Loc: " << x << " " << y << endl;
    }
}
*/
int main(){
    Mat img = imread("sample1.jpg");
    if(img.empty()){
        cout << "Fail to load image" << endl;
        cin.get();
        return -1;
    }
    namedWindow("Img",1);
    setMouseCallback("Img", mouseEvent, NULL);
    imshow("Img", img);
    waitKey(0);
    return 0;
}