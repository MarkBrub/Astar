#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "astar.hpp"

cv::Mat getImage(std::string name);
std::vector<std::vector<Node>> generateGraph(cv::Mat* img);