#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace cv;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0;
VideoCapture g_cap;

void onTrackbarSlide(int pos, void *){
    g_cap.set(CAP_PROP_POS_FRAMES, pos);
    if( !g_dontset )
        g_run = 1;
    g_dontset = 0;
}

int main(){
    namedWindow("Ex2", WINDOW_AUTOSIZE);
    g_cap.open("sampleV.mp4");
    int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
    int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
    int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);

    createTrackbar("Position", "Ex2", &g_slider_position, frames, onTrackbarSlide);
    Mat frame;
    while(true){
        if(g_run != 0){
            g_cap >> frame;
            if(frame.empty()) break;
            int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            setTrackbarPos("Position", "Ex2", current_pos);
            imshow("Ex2", frame);
            g_run -= 1;
        }
        char c = (char)waitKey(10);
        if(c == 's'){
            g_run = 1;
        }else if(c == 'r'){
            g_run = -1;
        }else if(c == 27){
            break;
        }
    }
    return 0;
}