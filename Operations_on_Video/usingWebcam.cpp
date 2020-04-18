#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(int argc, char **args){
    VideoCapture cap(0);
    if(cap.isOpened() == false){
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }
    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << "Res: " << dWidth << "x" << dHeight << endl;
    string winName = "WebCam Record";
    namedWindow(winName);
    while(true){
        Mat frame;
        bool success = cap.read(frame);
        if (success == false){
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }
        imshow(winName, frame);
        if (waitKey(10) == 27){
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }

    }
    return 0;
}