#include <opencv2/opencv.hpp>
#include <string>
#include "util.hpp"

using namespace std;
using namespace cv;

Mat getImage(string name) {
	const int THRESHOLD_VALUE = 185;
	const int MAX_VALUE = 255;
	Mat img = imread(name);

	if (img.empty()) {
		std::cout << "Image not loaded";
		return -1;
	}

	resize(img, img, Size(), 0.15, 0.15);
	cvtColor(img, img, COLOR_BGR2GRAY);
	threshold(img, img, THRESHOLD_VALUE, MAX_VALUE, 0);
	blur(img, img, Size(3, 3), Point(-1, -1));
	threshold(img, img, 200, MAX_VALUE, 0);

	return img;
}