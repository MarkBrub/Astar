#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "astar.hpp"

cv::Mat getImage(std::string name, float xScale = 1, float yScale = 1);
void bolden(cv::Mat* img, double threshold = 200);
void crispen(cv::Mat* img, double threshold = 200);
std::vector<std::vector<Node>> generateGraph(cv::Mat* img);