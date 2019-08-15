#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "astar.hpp"

cv::Mat getImage(std::string name, float xScale = 1, float yScale = 1, bool crispen = false);
std::vector<std::vector<Node>> generateGraph(cv::Mat* img);