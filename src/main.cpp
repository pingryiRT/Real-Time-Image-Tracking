//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <stdio.h>
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
int threshold (uchar targetB, uchar targetG, uchar targetR, uchar b, uchar g, uchar r, int t ){
	if (MAX(targetB,b)-MIN(targetB,b) > t)
		return false;
	if (MAX(targetG,g)-MIN(targetG,g) > t)
		return false;
	if (MAX(targetR,r)-MIN(targetR,r) > t)
		return false;
	return true;
};
//using namespace cv;
int main(int argc, char** argv)
{
    cv::VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(0))
        return 0;
    while(true)
    {
          cv::Mat frame;
          cap >> frame;
          if( frame.empty() ) break; // end of video stream
          imshow("camera", frame);
          if( cv::waitKey(10) == 27 )
		break; // stop capturing by pressing ESC 
    }
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;
}
 	 	 
