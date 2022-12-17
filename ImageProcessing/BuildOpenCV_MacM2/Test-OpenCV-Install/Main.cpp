#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() 
{
    string path = "./TestJPG.jpg";
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);
    return 0;
}
