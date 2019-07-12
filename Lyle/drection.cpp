#include "direction.hpp"

direction::Direction direction::getDirection(int x, int y) {
	if (x == 0 && y == 0) {
		return ERROR;
	}
	else if (x == 1 && y == 0) {
		return S;
	}
	else if (x == 1 && y == -1) {
		return SW;
	}
	else if (x == 0 && y == -1) {
		return W;
	}
	else if (x == -1 && y == -1) {
		return NW;
	}
	else if (x == -1 && y == 0) {
		return N;
	}
	else if (x == -1 && y == 1) {
		return NE;
	}
	else if (x == 0 && y == 1) {
		return E;
	}
	else if (x == 1 && y == 1) {
		return SE;
	}

	return ERROR;
}