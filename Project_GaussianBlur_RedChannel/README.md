## Project_GaussianBlur_RedChannel

C++ application which can: 
A. Provide simple login-logout feature 
B. Record a short 10-second video from the webcam 
C. Extract the red channel from the frames 
D. Add a gaussian filter to these frames 
E. Store this video on the disk 
F. Show a list of videos recorded in such a way 

Done using OpenCV
To compile the code write the following command in terminal:
g++ -o [output_file_name] main.cpp `pkg-config --cflags --libs opencv`