#pragma once

struct Position {
	int x = 0;
	int y = 0;

	Position(int m_x = -1, int m_y = -1);

	bool operator == (Position right);

	bool operator != (Position right);

	Position delta(int dx, int dy);
};