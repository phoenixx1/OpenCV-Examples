## Project_GaussianBlur_RedChannel

#### C++ application which can:
1. Provide simple login-logout feature 
2. Record a short 10-second video from the webcam 
3. Extract the red channel from the frames 
4. Add a gaussian filter to these frames 
5. Store this video on the disk 
6. Show a list of videos recorded in such a way 

Code written using OpenCV.
To compile the code write the following command in terminal:

`g++ -o [output_file_name] main.cpp 'pkg-config --cflags --libs opencv'` 

[To install OpenCV in Linux](http://www.codebind.com/linux-tutorials/install-opencv-ubuntu-18-04-lts-c-cpp-linux/)
