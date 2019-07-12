#include <opencv2/opencv.hpp>
#include <string>
#include "image.hpp"
#include "astar.hpp"

cv::Mat getImage(std::string name) {
	const int THRESHOLD_VALUE = 185;
	const int MAX_VALUE = 255;
	cv::Mat img = cv::imread(name);

	if (img.empty()) {
		std::cout << "Image not loaded";
		return img;
	}

	//the following lines need to be changd to suit the image being used
	//cv::resize(img, img, cv::Size(), 0.5, 0.5);
	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
	cv::threshold(img, img, THRESHOLD_VALUE, MAX_VALUE, 0);
	//the blur and following threshold should only be used if the lines are not already clearly defined
	//cv::blur(img, img, cv::Size(3, 3), cv::Point(-1, -1));
	cv::threshold(img, img, 200, MAX_VALUE, 0);

	return img;
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