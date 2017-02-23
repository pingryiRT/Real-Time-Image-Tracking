import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfByte;
import org.opencv.imgcodecs.Imgcodecs;
//import org.opencv.videoio.VideoCapture;
import org.opencv.imgproc.Imgproc;

public class Benchmark {
	public static void main(String[] args){
		System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
		Mat m = Imgcodecs.imread("benchmark.jpg");
		int x = 0;
		int y = 0;
		int count = 0;
		// BGR
		double[] color = {255.0,255.0,0};
		for (int i = 0; i < m.rows(); i++){
			for (int j = 0; j < m.cols(); j++){
				if (threshold(m.get(i,j),color,30)){
					x += j;
					y += i;
					count++;

				}
			}
		}
		System.out.format("(%d,%d)", x/count, y/count);
	}
	public static boolean threshold(double[] a, double[] b, int t){
		for (int i = 0; i < a.length; i++)
			if (Math.abs(a[i] - b[i]) > t)
				return false;
		return true;
	}
}
