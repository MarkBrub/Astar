#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include "position.hpp"
#include "maze.hpp"

void Maze::SetPoints(int event, int x, int y, int flags, void* maze) {
	static int selectedPoints = 0;
	Maze* m = (Maze*)maze;

	if (event == cv::EVENT_LBUTTONDOWN && selectedPoints == 0) {
		selectedPoints++;
		m->start.x = y * m->scale;
		m->start.y = x * m->scale;
		std::cout << "First point selected at (" << m->start.x << ", " << m->start.y << ")" << std::endl;
	}
	else if (event == cv::EVENT_LBUTTONDOWN && selectedPoints == 1) {
		selectedPoints++;
		m->end.x = y * m->scale;
		m->end.y = x * m->scale;
		std::cout << "First point selected at (" << m->end.x << ", " << m->end.y << ")" << std::endl;
	}
}