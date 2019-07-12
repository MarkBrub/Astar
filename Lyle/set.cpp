#include "node.hpp"
#include "set.hpp"

Node*& Set::operator [] (int x) {
	return set[x];
}

void Set::add(Node* node) {
	set.push_back(node);
}

void Set::remove(Node* node) {
	for (int x = 0; x < set.size(); x++) {
		if (set[x] == node) {
			set.erase(set.begin() + x);
			return;
		}
	}
}

bool Set::inSet(Node* node) {
	for (int x = 0; x < set.size(); x++) {
		if (set[x] == node) return true;
	}
	return false;
}

Node* Set::getLowestCost() {
	Node* lowestCost = (set)[0];

	for (unsigned int x = 1; x < set.size(); x++) {
		if (set[x]->f < lowestCost->f) lowestCost = set[x];
	}

	return lowestCost;
}
