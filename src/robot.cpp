#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;
int threshold (uchar targetB, uchar targetG, uchar targetR, uchar b, uchar g, uchar r, int t ){
	if (MAX(targetB,b)-MIN(targetB,b) > t)
		return false;
	if (MAX(targetG,g)-MIN(targetG,g) > t)
		return false;
	if (MAX(targetR,r)-MIN(targetR,r) > t)
		return false;
	return true;
};
int main( int argc, char** argv )
{
	VideoCapture cap(0);
	// open the default camera, use something different from 0 otherwise;
	// Check VideoCapture documentation.
	if(!cap.open(0))
		return 0;
	while (true){
		Mat frame;
		cap >> frame;
		if(frame.empty())
			break;
		uchar r = 0;
		uchar g = 255;
		uchar b = 255;
		int t = 15;
		int count = 0;
		int x = 0;
		int y = 0;
		for(int i = 0; i < frame.rows; i++){
			for(int j = 0; j < frame.cols; j++){
				Vec3b pixel = frame.at<Vec3b>(Point(j,i));
				if (threshold(b,g,r,pixel.val[0],pixel.val[1],pixel.val[2],t)){
					x += j;
					y += i;
					count += 1;
				}
			}
		}
		if (count == 0){
			x = 0;
			y = 0;
		}else{
			x /= count;
			y /= count;
		}
		printf("(%d,%d) c:%d \n",x,y,count);
		// transfer data here
		
	}
	return 0;
}
 	 	 
