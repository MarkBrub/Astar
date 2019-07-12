#pragma once
#include <vector>
#include "node.hpp"

//the set class is used to handle the open and closed set
struct Set {
	std::vector<Node*> set = {};

	Node*& operator [] (int x);

	void add(Node* node);

	void remove(Node* node);

	bool inSet(Node* node);

	Node* getLowestCost();
};