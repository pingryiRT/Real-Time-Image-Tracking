#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdio.h>
using namespace cv;
int threshold (uchar targetB, uchar targetG, uchar targetR, uchar b, uchar g, uchar r, int t ){
	if (MAX(targetB,b)-MIN(targetB,b) > t)
		return false;
	if (MAX(targetG,g)-MIN(targetG,g) > t)
		return false;
	if (MAX(targetR,r)-MIN(targetR,r) > t)
		return false;
	return true;
};
int main(int argc, char** argv){
	VideoCapture cap(0);
	// open the default camera, use something different from 0 otherwise;
	// Check VideoCapture documentation.
	if(!cap.open(0))
		return 0;
	Vec3b color;
	Scalar low;
	Scalar high;
	int t = 20;       
	int threshtoggle = false;
	namedWindow("camera",1);
	createTrackbar("Theshold:", "camera", &t, 255);
	resizeWindow("camera", 1280, 720);
	int r = 0; int g = 0; int b = 0;
	createTrackbar("Red:","camera",&r,255);
	createTrackbar("Green:","camera",&g,255);
	createTrackbar("Blue:","camera",&b,255);
	//createButton(NULL,NULL);
	while(true){
		Vec3b color = Vec3b(b,g,r);
		Mat frame;
		cap >> frame;
		if(frame.empty())
			break;
		Mat showframe;
		if (threshtoggle){
			low = Scalar(color.val[0]-t,color.val[1]-t,color.val[2]-t);
			high = Scalar(color.val[0]+t,color.val[1]+t,color.val[2]+t);
			inRange(frame, low, high, showframe);
		}else {
			showframe = frame;
		}
		
		int count = 0;
		int x = 0;
		int y = 0;
		for(int i = 0; i < frame.rows; i++){
			for(int j = 0; j < frame.cols; j++){
				cv::Vec3b pixel = frame.at<cv::Vec3b>(cv::Point(j,i));
				if (threshold(color.val[0],color.val[1],color.val[2],pixel.val[0],pixel.val[1],pixel.val[2],t)){
					x += j;
					y += i;
					count += 1;
				}
			}
		}
		
		if (count != 0){
			if (threshtoggle){
				circle(showframe,Point(x/count,y/count),10,Scalar(255,255,255),-1);
				circle(showframe,Point(x/count,y/count),10,Scalar(0,0,0),4 );
			}else{
				circle(showframe,Point(x/count,y/count),10,Scalar(b,g,r),-1);
			}
		}	
		imshow("camera", showframe);
		int key = waitKey(10);
		if( key == 27 ){
			break;
		}
		else if (key == 32){
			threshtoggle = !threshtoggle;
			
		}
	}
	return 0;
}


