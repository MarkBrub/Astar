#include <opencv2/opencv.hpp>
#include <string>
#include "image.hpp"
#include "astar.hpp"

//not currently being used
cv::Mat getImage(std::string name, float xScale, float yScale) {
	const int THRESHOLD_VALUE = 180;
	const int MAX_VALUE = 255;
	cv::Mat img = cv::imread(name);

	if (img.empty()) {
		std::cout << "Image not loaded";
		return img;
	}

	cv::resize(img, img, cv::Size(), xScale, yScale, 2);
	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

	return img;
}

void bolden(cv::Mat* img, double threshold) {
	cv::blur(*img, *img, cv::Size(3, 3), cv::Point(-1, -1));
	cv::blur(*img, *img, cv::Size(3, 3), cv::Point(-1, -1));
	cv::threshold(*img, *img, threshold, 255, 0);
	cv::blur(*img, *img, cv::Size(3, 3), cv::Point(-1, -1));
	cv::blur(*img, *img, cv::Size(3, 3), cv::Point(-1, -1));
	cv::threshold(*img, *img, threshold, 255, 0);
}

void crispen(cv::Mat* img, double threshold) {
	cv::threshold(*img, *img, threshold, 255, 0);
	cv::blur(*img, *img, cv::Size(3, 3), cv::Point(-1, -1));
	cv::threshold(*img, *img, threshold, 255, 0);
}

//convert a black and whit image into a graph
std::vector<std::vector<Node>> generateGraph(cv::Mat* img) {
	std::vector<std::vector<Node>> map;

	for (int x = 0; x < img->rows; x++)
	{
		//is there a better way to do this
		std::vector<Node> filler;
		map.push_back(filler);
		for (int y = 0; y < img->cols; y++)
		{
			Node node(x, y);
			if (img->at<uchar>(cv::Point(y, x)) == 0) node.f = 0;
			map[x].push_back(node);
		}
	}

	return map;
}