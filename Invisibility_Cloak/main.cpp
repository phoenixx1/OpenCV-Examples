//author @Nishant

#include <opencv4/opencv2/opencv.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "Error" << endl;
        return -1;
    }

    Mat background;
    for (int i = 0; i < 30; i++)
    {
        cap >> background;
    }

    flip(background, background, 1);

    while (1)
    {
        Mat frame;
        cap >> frame;

        flip(frame, frame, 1);

        Mat hsv;
        cvtColor(frame, hsv, COLOR_BGR2HSV);

        Mat mask1, mask2;
        inRange(hsv, Scalar(0, 120, 70), Scalar(10, 255, 255), mask1);
        inRange(hsv, Scalar(170, 120, 70), Scalar(180, 255, 255), mask2);

        mask1 = mask1 + mask2;

        Mat kernel = Mat::ones(3, 3, CV_32F);
        morphologyEx(mask1, mask1, cv::MORPH_OPEN, kernel);
        morphologyEx(mask1, mask1, cv::MORPH_DILATE, kernel);


        bitwise_not(mask1, mask2);
        Mat res1, res2, final_output;

        bitwise_and(frame, frame, res1, mask2);

        bitwise_and(background, background, res2, mask1);

        addWeighted(res1, 1, res2, 1, 0, final_output);
        imshow("magic", final_output);
        waitKey(27);
    }

    cap.release();

    destroyAllWindows();
    return 0;
}