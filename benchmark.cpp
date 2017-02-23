#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
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
	cv::Mat m;
	m = cv::imread("benchmark.jpg", CV_LOAD_IMAGE_COLOR);
	uchar r = 0;
	uchar g = 255;
	uchar b = 255;
	int t = 20;
	int count = 0;
	int x = 0;
	int y = 0;
	for(int i = 0; i < m.rows; i++){
		for(int j = 0; j < m.cols; j++){
			cv::Vec3b pixel = m.at<cv::Vec3b>(cv::Point(j,i));
			if (threshold(b,g,r,pixel.val[0],pixel.val[1],pixel.val[2],t)){
				x += j;
				y += i;
				count += 1;
			}
		}
	}
	if (count == 0){
		printf("(0,0)\n");
	}else{
		printf("(%d,%d)\n",x/count,y/count);
	}
	return 0;
}
 	 	 
