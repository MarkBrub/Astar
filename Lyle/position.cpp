#include "position.hpp"

Position::Position(int m_x, int m_y) {
	x = m_x;
	y = m_y;
}

bool Position::operator == (Position right) {
	return x == right.x && y == right.y;
}

Position Position::delta(int dx, int dy) {
	Position neighbor(x + dx, y + dy);
	return neighbor;
}