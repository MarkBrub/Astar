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
	std::string filename = "test.jpg";
	Maze maze;
	maze.scale = 1;

	cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
	maze.img = cv::imread(filename);
	cv::cvtColor(maze.img, maze.img, cv::COLOR_BGR2GRAY);
	bolden(&maze.img);

	cv::imshow("Image", maze.img);
	cv::setMouseCallback("Image", Maze::SetPoints, &maze);

	cv::waitKey(0);

	std::cout << "Working..." << std::endl;

	cv::resize(maze.img, maze.img, cv::Size(), maze.scale, maze.scale, 2);

	//converts the image in to the custom graph type
	Graph graph(generateGraph(&maze.img));

	//start timer
	auto startTimer = std::chrono::system_clock::now();

	//runs astar on the graph
	Node* path = aStar(&graph, &maze.start, &maze.end, &maze.img);

	//end timer
	auto endTimer = std::chrono::system_clock::now();

	//if a path was found
	if (path->position == maze.end) {
		std::cout << "Path found in: "
			<< std::chrono::duration_cast<std::chrono::milliseconds>(endTimer - startTimer).count()
			<< " milliseconds" << std::endl;

		drawPath(path, &maze.img);

		cv::resize(maze.img, maze.img, cv::Size(), 1 / maze.scale, 1 / maze.scale, 3);

		cv::imshow("Image", maze.img);
	}
	cv::waitKey(0);

	return 0;
}