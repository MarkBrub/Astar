#pragma once
#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>
#include <math.h>
#include "position.hpp"
#include "node.hpp"
#include "set.hpp"
#include "graph.hpp"
#include "direction.hpp"

Node aStar(Graph* graph, Position* start, Position* end, cv::Mat* img = nullptr);

void drawPath(Node node, cv::Mat* img);

void outputDirections(Node node);