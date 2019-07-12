#pragma once
#include <vector>
#include "position.hpp"
#include "node.hpp"

struct Graph {
	std::vector<std::vector<Node>> graph;

	Graph(std::vector<std::vector<Node>> m_graph);

	std::vector<Node>& operator [] (int x);

	int size();

	Node* getNode(Position position);
};