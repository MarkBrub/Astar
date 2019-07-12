#pragma once

struct Position {
	int x = 0;
	int y = 0;

	Position(int m_x = 0, int m_y = 0);

	bool operator == (Position right);

	Position delta(int dx, int dy);
};