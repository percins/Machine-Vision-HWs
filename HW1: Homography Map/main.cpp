#include "Header.h" // header containing all the necessary methods

//including library (Visual Studio)
#pragma comment (lib, "opencv_world455.lib")


int main()
{
    
    //Image that will be used in comparison
    Mat img1 = imread(imagepath1);
    //Image that the homography will be applied on
    Mat img2 = imread(imagepath2);
    
    //Taking the number of the points that will be used in mapping between two images:
    cout << "Please enter the number N of input corresponding points: ";
    cin >> N;
    //Showing the images
    imshow("Image1", img1);
    imshow("Image2", img2);

    //Triggering the callback function that will be used on the windows for the click position obtaining
    setMouseCallback("Image1", CallBackFunc);
    setMouseCallback("Image2", CallBackFunc);
    
    //After the selection of the corresponding points between windows one after another, any keypress is waited to close the windows
    waitKey(0);
    destroyAllWindows();
    
    //The point positions stored in Mat object "V" are taken bakc to the corresponding point vectors d' (d1) and d (d2)
    vector <Point> d1;
    vector <Point> d2;
    for (int i = 0; i < N; i++) {
        d1.push_back(V.at(i * 2));
        d2.push_back(V.at(i * 2 + 1));
    }

    //Writing the points to a file for MATLAB to obtain them:
    pointstoFile(d1,d2);

    //Checking the process continuing on the MATLAB end. If the process is completed and the manualH.txt file is formed,
    //the user is asked to press y as input, then the process continues
    cout << "Please run the MATLAB program that will create the manualH.txt file." << "\n";
    char flag = 'n';
    while(flag!='y') {
        cout << "Is the manualH.txt file created (y/n):    ";
        cin >> flag;
    }
    
    //Reading the manually obtained homography map from matlab and storing
    Mat Hmanual = homographyMapManuallyInput();
    //Obtaining the homography map from the OpenCV API using 2D points vectors
    Mat Hopencv = findHomographyMap(d2, d1);
    
    //Displaying the matrices
    cout << "Hmanual:\n";
    cout << Hmanual << endl;;
    cout << "Hopencv:\n";
    cout << Hopencv << endl;

    //Applying the homography maps to the images
    Mat outputmanual;
    Mat outputopencv;
    warpPerspective(img2, outputmanual, Hmanual, img2.size());
    warpPerspective(img2, outputopencv, Hopencv, img2.size());

    //Displaying all the results
    Mat img3;
    hconcat(img1, outputmanual, img3);
    hconcat(img3, outputopencv, img3);
    imshow("Results",img3);

    //Writing images for the report
    imwrite("result6.png", img3);
    waitKey(0);

    return 0;
}