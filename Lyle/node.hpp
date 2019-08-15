#pragma once
#include <math.h>
#include "position.hpp"

struct Node {
	Position position;
	float g = INFINITY;
	float f = INFINITY;
	bool closed = false;
	Node* parent = nullptr;

	Node(int x, int y);

	bool operator == (Node right);

	double distance(Node* target);
};