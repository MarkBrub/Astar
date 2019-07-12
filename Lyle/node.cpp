#include "position.hpp"
#include "node.hpp"

Node::Node(int x, int y) {
	position.x = x;
	position.y = y;
}

bool Node::operator == (Node right) {
	return position == right.position;
}

double Node::distance(Node* target) {
	return sqrt(pow(target->position.x - position.x, 2) + pow(target->position.y - position.y, 2));
}