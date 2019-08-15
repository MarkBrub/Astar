#pragma once
#include <opencv2/opencv.hpp>
#include "graph.hpp"
#include "position.hpp"

struct Maze {
	cv::Mat img;
	Graph graph;
	Position start;
	Position end;
	float scale;

	static void SetPoints(int event, int x, int y, int flags, void* points);
};