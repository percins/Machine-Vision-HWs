#include <string>;
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>
#include <fstream> 
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc.hpp>
//Header file containing the methods to be used in the main script

//including the namespaces
using namespace cv;
using namespace std;

//including library (Visual Studio)
#pragma comment (lib, "opencv_world455.lib")

//path parameters
string imagepath1 = "Imagepath1";
//the transformations will be applied to this image
string imagepath2 = "Imagepath2";

//Method that saves the mouse click positions to a global variable of type 2d vector of points called "V"
// When used, clicks of corresponding points should be done on windows one after another starting from the one that the
// homography map will not be applied on
//Ref = https://www.opencv-srf.com/2011/11/mouse-events.html
vector <Point> V;
int N;
int it = 0;
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
        if (it < N * 2) {
            //Saving click positionsto the global variable of type Vector
            V.push_back(Point2i(x, y));
            it++;
        }
    }
}

//Method reading the manually found homograpy map matrix from the text file formed using MATLAB where the
//linear equations were solved. The file is named as "manualH.txt" in the script findH.m
Mat homographyMapManuallyInput() {
    double inputdouble;
    //opening the information carrying file
    ifstream inputfile("manualH.txt");
    double hrow[9];
    Mat Hmanual = Mat(3, 3, CV_64FC1);
    //reading information into a double array called hrow
    int m = 0;
    while (inputfile >> inputdouble) {
        hrow[m] = inputdouble;
        m++;
    }
    //transporting the values to a Mat object Hmanual containing elements of double type since it is the desired 
    //map format by the warpPerspective() method in OpenCV
    m = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Hmanual.at<double>(i, j) = hrow[m];
            m++;
        }
    }
    inputfile.close();
    return Hmanual;
}

//Method to return the homography map using the findHomography() method of OpenCV
Mat findHomographyMap(vector <Point> d_source, vector <Point> d_dest) {
    Mat Hopencv = findHomography(d_source, d_dest);
    return Hopencv;
}
//Method writing the points' position information to a text file called "points.txt" that will be later read by MATLAB
//for the formation of the linear equations whose solution will provide the manually found homography map
void pointstoFile(vector <Point> d1, vector <Point> d2) {
    ofstream pointsfile("points.txt");
    for (int i = 0; i < d1.size(); i++) {
        pointsfile << d1.at(i).x << " " << d1.at(i).y << " " << d2.at(i).x << " " << d2.at(i).y << "\n";
    }
    pointsfile.close();
}



