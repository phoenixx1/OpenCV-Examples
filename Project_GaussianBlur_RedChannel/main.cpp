//author @Nishant

#include<opencv2/opencv.hpp>
#include<bits/stdc++.h>
#include<dirent.h>
#include<time.h>
#ifdef WINDOWS
  #include <direct.h>
  #define GetCurrentDir _getcwd
#else
  #include <unistd.h>
  #define GetCurrentDir getcwd
#endif

using namespace std;
using namespace cv;

void videoCapture(int);
void viewVideo();
string getPath();

int main(){
    string usrname, password;
    //for this program I have not maintained any database
    // I'll check if the username and password is admin
    int noOfTries = 3, choice;
    bool success = false;
    system("clear");
    while(noOfTries){
        cout << "Username: ";
        cin >> usrname;
        cout << "Password: ";
        cin >> password;
        if(usrname == "admin" && password == "admin"){
            system("clear");
            
            cout << "Credentials verified" << endl;
            cout << endl;
            
            int count = 1;
            do{
                cout << "Choose from below to add Gaussian filter to red channel:\n";
                cout << "1. Record a 10 second video from webcam\n";
                cout << "2. View saved videos from webcam\n";
                cout << "3. Log out\n\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice){
                    case 1:
                        videoCapture(count);
                        count++;
                        break;

                    case 2:
                        viewVideo();
                        break;

                    case 3:
                        cout << "Logged out" << endl;
                        break;

                    default:
                        cout << "Invalid Option\n\n";
                        break;
                }
            }while(choice!=3);
        }else{
            system("clear");
            noOfTries--;
            if(noOfTries > 0){
                cout << noOfTries << " tries left, Try again" << endl;
            }else{
                cout << "Limit reached contact admin\n\n";
            }
        }
        if(choice == 3){
            break;
        }
    }
}

void videoCapture(int n){
    VideoCapture cap(0);
    if(cap.isOpened() == false){
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
    }

    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);

    Size frameSize(dWidth, dHeight);
    int fps = 15;//set according to the system to sync fps and video processing time to get video of desired length
    string name = "output" + to_string(n) + ".avi";

    VideoWriter videoWrt(name, CV_FOURCC('M','J','P','G'), fps, frameSize, true);

    if(!videoWrt.isOpened()){
        cout << "Cannot save the video to a file" << endl;
        cin.get(); //wait for any key press
    }

    string winName = "Webcam Record";

    time_t start = time(0);
    while(true){    
        Mat frame;
        
        cap >> frame;

        Mat bgr[3];
        
        split(frame, bgr);

        Mat g, red, rest;
        g = Mat::zeros(Size(frame.cols, frame.rows), CV_8UC1); //creating channel with 0 intensity
        
        vector<Mat> channels;
        channels.push_back(g);
        channels.push_back(g);
        channels.push_back(bgr[2]); //only red channel of a frame
        merge(channels, red); //creating a frame of only red channel
        GaussianBlur(red, red, Size(3,3), 0); //applying Gaussian Blur to red channel

        vector<Mat> channels1;
        channels1.push_back(bgr[0]);
        channels1.push_back(bgr[1]);
        channels1.push_back(g);
        merge(channels1, rest);//creating a frame of blue and green channel

        Mat final = rest + red; //adding both frames
        videoWrt.write(final); //saving the above output frame 

        imshow(winName, frame); //showing original webcam view
        waitKey(33);
        
        if(difftime(time(0), start) >= 10) break;//to break the while loop after 10 seconds of recording
    }
    cvDestroyAllWindows();
    videoWrt.release();
    cap.release();
    system("clear");
    cout << "Gaussian filtered applied to red channel"<< endl;
    cout << "Saved as: " << name << "\n\n";
}

void viewVideo(){
    DIR *di;
    char *ptr1,*ptr2;
    int retn;
    struct dirent *dir;
    string vName;
    string fName = "Project_GaussianBlur_RedChannel";//change the folder name in case you take code file to some other folder
    string path = getPath();
    if(path.find('/')!=string::npos){
        if(path.find(fName)== string::npos){//for Linux
            path = path + "/" + fName;
        }
    }else{
        if(path.find(fName)== string::npos){//for windows
            path = path + "\\" + fName;
        }
    }

    di = opendir(path.c_str()); //specify the directory path

    if (di){
        while ((dir = readdir(di)) != NULL){
            ptr1=strtok(dir->d_name,".");
            ptr2=strtok(NULL,".");

            if(ptr2!=NULL){
                retn=strcmp(ptr2,"avi");
                if(retn==0){
                    cout<<ptr1<<endl;
                }
            }
        }
        closedir(di);
    }
    if(retn==0){
        cout << "Enter file you want to play: ";
        cin >> vName;
        vName += ".avi";
        
        VideoCapture cap(vName);
        if(cap.isOpened() == false){
            cout << "Cannot open the video file" << endl;
            cin.get(); //wait for any key press
        }
        while(true){
            Mat frame;
            bool bSuccess = cap.read(frame);
            if(bSuccess == false){
                break;
            }
            imshow(vName, frame);
            if (waitKey(10) == 27){
                cout << "Esc key is pressed by user.\nStopping the video" << endl;
                break;
            }
        }
        destroyAllWindows();
        system("clear"); 
    }else{
        system("clear"); 
        cout << "No file found\n\n";
    }
       
}

string getPath(){
    char cCurrentPath[FILENAME_MAX];
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))){
        return "0";
    }
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';

    return cCurrentPath;
}