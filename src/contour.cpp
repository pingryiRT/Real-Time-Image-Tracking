#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace cv;
using namespace std;
int main(int argc, char** argv){
	VideoCapture cap(0);
	// open the default camera, use something different from 0 otherwise;
	// Check VideoCapture documentation.
	if(!cap.open(0))
		return 0;
	int thresh = 90;
	int black = false;
	while(true){
		Mat frame;
		cap >> frame;
		if(frame.empty())
			break;
		Mat gray;
		cvtColor(frame, gray, CV_BGR2GRAY);
		Mat canny_output;
  		vector<vector<Point> > contours;
  		vector<Vec4i> hierarchy;
  		/// Detect edges using canny
  		Canny( gray, canny_output, thresh, thresh*2, 3 );
  		/// Find contours
		if(black)
			frame = Mat::zeros( frame.size(), CV_8UC3 );
  		findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
		for( int i = 0; i< contours.size(); i++ )
     		{
       			drawContours( frame, contours, i, Scalar(255,0,0), 2, 8, hierarchy, 0, Point() );
     		}
		imshow("camera", frame);
		int key = waitKey(10);
		if( key == 27 ){
			break;
		}else if (key == 32){
			black = !black;
		}
	}
	return 0;
}


