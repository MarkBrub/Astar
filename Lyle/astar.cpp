#include "astar.hpp"

Node* aStar(Graph* graph, Position* start, Position* end, cv::Mat* img) {
	Set openSet;

	//automaticly put all wall nodes in the closed set
	for (int x = 0; x < graph->size(); x++) {
		for (int y = 0; y < (*graph)[0].size(); y++) {
			if ((*graph)[x][y].f == 0) {
				(*graph)[x][y].closed = true;
				if (img != nullptr) img->at<uchar>(cv::Point(y, x)) = 128;
			}
		}
	}

	openSet.add(graph->getNode(*start));
	openSet[0]->g = 0;
	openSet[0]->f = openSet[0]->distance(graph->getNode(*end));

	while (!openSet.set.empty()) {

		Node* currentNode = openSet.getLowestCost();

		if (currentNode->position == *end) return graph->getNode(*end);

		openSet.remove(currentNode);
		currentNode->closed = true;

		std::vector<Node*> neighbors;
		Position position = currentNode->position;

		neighbors.push_back(graph->getNode(position.delta(-1, 1)));
		neighbors.push_back(graph->getNode(position.delta(0, 1)));
		neighbors.push_back(graph->getNode(position.delta(1, 1)));
		neighbors.push_back(graph->getNode(position.delta(-1, 0)));
		neighbors.push_back(graph->getNode(position.delta(1, 0)));
		neighbors.push_back(graph->getNode(position.delta(-1, -1)));
		neighbors.push_back(graph->getNode(position.delta(0, -1)));
		neighbors.push_back(graph->getNode(position.delta(1, -1)));

		for (int x = 0; x < neighbors.size(); x++) {

			if (neighbors[x]->closed) continue;

			float g = currentNode->g + currentNode->distance(neighbors[x]);

			if (!openSet.inSet(neighbors[x])) {
				openSet.add(neighbors[x]);
			}
			else if (g >= neighbors[x]->g) {
				continue;
			}

			if (img != nullptr) img->at<uchar>(cv::Point(neighbors[x]->position.y, neighbors[x]->position.x)) = 180;

			neighbors[x]->parent = currentNode;
			neighbors[x]->g = g;
			neighbors[x]->f = g + neighbors[x]->distance(graph->getNode(*end));
		}

	}
	std::cout << "No path was found" << std::endl;
	return graph->getNode(*start);
}

//follows each node to its parent until reaching the start node
void drawPath(Node* path, cv::Mat* img) {
	cv::cvtColor(*img, *img, cv::COLOR_GRAY2BGR);
	img->at<cv::Vec3b>(cv::Point(path->position.y, path->position.x)) = { 0, 0, 255 };
	path = path->parent;

	while (path->parent != nullptr) {
		img->at<cv::Vec3b>(cv::Point(path->position.y, path->position.x)) = { 255, 0, 0 };
		path = path->parent;
	}

	img->at<cv::Vec3b>(cv::Point(path->position.y, path->position.x)) = { 0, 255, 0 };
}

//simplify and output the steps taken to a file
void outputDirections(Node path) {
	std::vector<std::pair<direction::Direction, int>> directions;

	while (path.parent != nullptr) {
		std::pair<direction::Direction, int> dir = { direction::getDirection(path.position.x - path.parent->position.x, path.position.y - path.parent->position.y), 1 };
		directions.push_back(dir);
		path = *path.parent;
	}

	std::reverse(directions.begin(), directions.end());

	for (unsigned int x = 0; x < directions.size() - 1; x++) {
		if (directions[x].first == directions[x + 1].first) {
			directions[x + 1].second += directions[x].second;
			directions.erase(directions.begin() + x);
			x--;
		}
	}

	std::ofstream file("output.txt");

	for (unsigned int x = 0; x < directions.size() - 1; x++) {
		file << directions[x].first << ", " << directions[x].second << std::endl;
	}

	file.close();
}
