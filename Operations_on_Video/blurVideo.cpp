#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {
    // Read the video
    VideoCapture cap("sample.mp4");
    if (cap.isOpened() == false) {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }
    double fps = cap.get(CAP_PROP_FPS);
    string vName = "Blur Video";
    namedWindow(vName);
    while (true) {
        Mat frame;
        bool bSuccess = cap.read(frame);
        if (bSuccess == false) {
            cout << "Found the end of the video" << endl;
            break;
        }
        // To blur the image.
        // Blur the current frame and save it to same variable.
        blur(frame, frame, Size(10, 10)); 

        /* 
        Optional
        
        // Gaussian Blur saving frame of input video into
        // other frame which can be displayed using imshow
         Mat blur3x3;
         GaussianBlur(frame, blur3x3, Size(3, 3), 0);
         Mat blur5x5;
         GaussianBlur(frame, blur5x5, Size(5, 5), 0);

         */

        imshow(vName, frame);
        if (waitKey(10) == 27) {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }
    return 0;
}