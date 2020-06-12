#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** args) {
    // Import the sample Video
    VideoCapture cap("sample.mp4");

    // Check if video is imported successfully
    if (cap.isOpened() == false) {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    // To find length of video in MM:SS
    int frameNumbers = (int)cap.get(CAP_PROP_FRAME_COUNT);
    int fps = (int)cap.get(CAP_PROP_FPS);
    int videoLength = frameNumbers / fps;
    cout << "Video Length (MM:SS): " << videoLength / 60 << ":" << videoLength % 60 << endl;

    // Taking input from user for cutting portion of video
    // start and end time
    double startM, startS, endM, endS;
    cout << "Enter start time of video (MM SS): ";
    cin >> startM >> startS;
    cout << "Enter end time of video (MM SS): ";
    cin >> endM >> endS;
    cout << endl;
    
    // Error handling if the inputed time
    // is greater than video length
    if (startM > videoLength / 60 || endM > videoLength / 60) {
        cout << "Invalid Input interval" << endl;
        cin.get();
        return -1;
    }

    // Creating frame for output video
    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
    Size frameSize(dWidth, dHeight);

    // VideoWriter used for creating video
    VideoWriter videoWrt("output.mp4", VideoWriter::fourcc('M', 'J', 'P', 'G'), cap.get(CAP_PROP_FPS), frameSize, true);

    double startTime = startM + startS / 60.0;
    double endTime = endM + endS / 60.0;

    // Converting startTime and EndTime into frame
    double startFrame = cap.get(CAP_PROP_FPS) * 60 * startTime;
    double endFrame = cap.get(CAP_PROP_FPS) * 60 * endTime;

    double frameCount = 0;

    Mat frame;

    // Logic for cutting the video from 
    // start time to end time
    while (1){
        frameCount++;

        cap.read(frame);

        if (frameCount >= startFrame && frameCount < endFrame){
            videoWrt.write(frame);
        }
        else if (frameCount == endFrame){
            break;
        }
    }
    cout << "Video successfully saved with name output.mp4" << endl;
    return 0;
}
