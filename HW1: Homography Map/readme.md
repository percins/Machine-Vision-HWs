
This project aims to find the homography map betwen two images using MATLAB and OpenCV.
The files in the folder can be described as below:

-main.cpp : The main c++ script running the processes
-Header.h : Header file of the script containing the necessary custom functions and the parameters.
-mainH.txt : MATLAB script solving the linear equations using points provided by main.cpp
-readme.md : The file you are reading explaining the script and the content of the folder

The information regarding the script and its component can be found below. Script runs as describes:

1) The input should be written to the image paths imagepath1-imagepath2 declared in the Header.h.
   The imagepath2 is the image where the transformations will be applied on.

2) After the start of the main script the number of the points that will be used is asked to the user.
   User should give a number and press Enter. Two images will be shown afterwards.

3) Starting from the window labeled "Image1" user should click on the points one after onether changing between the windows.
   E.g clicking (x,y) on the Image1 window, then afterwards clicking on the correspondent (a,b) on window Image2,clicking on the (x2,y2) on Image1 window, clicking correspondent(a2,b2) on window Image2 etc.

4) When the necessary number of points are chosen, user should press Enter and the windows will be closed saving the position of the images to the points.txt file.

5) When the prompt asks if the MATLAB file is run or not, user should run the script mainH.m in the folder.
   Solution to the linear equations, the obtained homography matrix, will be written to the manualH.txt file. Afterwards user should press 'y' and press enter.

6) The resultant images and the matrices obtained using MATLAB and OpenCV will be displayed.
