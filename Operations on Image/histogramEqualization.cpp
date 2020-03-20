// histogram equalisation over an image
/*
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("sample.jpg",IMREAD_GRAYSCALE);
    
    if(image.empty()){
        cout << "Could not load image" << endl;
        cin.get();
        return -1;
    }
    //covert image to grayscale
    //cvtColor(image, image, COLOR_BGR2GRAY);

    Mat eqlHist;
    equalizeHist(image, eqlHist);

    imshow("Original", image);
    imshow("Changed", eqlHist);

    waitKey(0);

    destroyAllWindows(); 

    return 0;

}
*/

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("sample.jpg");
    
    if(image.empty()){
        cout << "Could not load image" << endl;
        cin.get();
        return -1;
    }
    //covert image from BGR to YCrCb
    Mat eqlHist;
    cvtColor(image, eqlHist, COLOR_BGR2YCrCb);
    
    vector<Mat> vecChannels;
    split(eqlHist, vecChannels);

    equalizeHist(vecChannels[0], vecChannels[0]);

    merge(vecChannels, eqlHist);

    cvtColor(eqlHist, eqlHist, COLOR_YCrCb2BGR);

    imshow("Original", image);
    imshow("Changed", eqlHist);

    waitKey(0);

    destroyAllWindows(); 

    return 0;

}