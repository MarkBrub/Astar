#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include "image.hpp"
#include "astar.hpp"
#include "position.hpp"
#include "node.hpp"
#include "graph.hpp"
#include "maze.hpp"

int main() {
	Maze maze;
	maze.scale = .25;

	cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
	//maze.img = cv::imread("maze.jpg");
	//cv::imshow("Image", maze.img);
	//cv::setMouseCallback("Image", Maze::SetPoints, &maze);

	//cv::waitKey(0);
	Position start(5, 5);
	Position end(95, 95);

	maze.start = start;
	maze.end = end;

	//gets a black and white image from picture
	cv::Mat img = getImage("maze.jpg", maze.scale, maze.scale, false);

	//converts the image in to the custom graph type
	Graph graph(generateGraph(&img));

	//start timer
	auto startTimer = std::chrono::system_clock::now();

	//runs astar on the graph
	Node* path = aStar(&graph, &maze.start, &maze.end, &img);

	//end timer
	auto endTimer = std::chrono::system_clock::now();

	std::cout << "Path found in: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(endTimer - startTimer).count()
		<< " milliseconds" << std::endl;

	//if a path was found
	if (path->position != maze.start) {
		drawPath(path, &img);

		cv::resize(img, img, cv::Size(), 1 / maze.scale, 1 / maze.scale, 3);

		cv::imshow("Image", img);
		cv::waitKey(0);
	}

	return 0;
}