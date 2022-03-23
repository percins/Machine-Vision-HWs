
This project aims to find the homography map betwen two images using MATLAB and OpenCV. <br/>
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

Example Original Images:
![image](https://user-images.githubusercontent.com/100145922/159613766-d83131dc-6460-46af-b7ad-3517ae63be73.png)

Results (Expected Image - Image transformed (H_MATLAB) - Image transformed (H_OpenCV)):
![image](https://user-images.githubusercontent.com/100145922/159614700-af424019-b399-42a4-9d4c-f92577e8c2bf.png)

Manually found homogprahy map (MATLAB):            Homography map found by OpenCV API:
[ 2.348167   0.320193  -678.2812269999999            [ 2.17884790    0.2532428   -613.01642607
 -0.312874   2.381784  -342.300629                    -0.319304375   2.19878814  -298.64360831
  0.0        0.0        1.0              ]            -7.390049112   -9.0220420   1.0         ]
