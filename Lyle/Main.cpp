#include <opencv2/opencv.hpp>
#include <iostream>
#include "image.hpp"
#include "astar.hpp"
#include "position.hpp"
#include "node.hpp"
#include "graph.hpp"

int main() {
	//gets a black and white image from picture
	cv::Mat img = getImage("maze1.png");
	//converts the image in to the custom graph type
	Graph graph(generateGraph(&img));

	cv::namedWindow("Image", cv::WINDOW_NORMAL);

	Position start(4, 4);
	Position end(400, 400);
	//runs astar on the graph
	Node path = aStar(&graph, &start, &end, &img);

	drawPath(path, &img);
	//outputDirections(path);

	cv::imshow("Image", img);
	cv::waitKey(0);

	return 0;
}