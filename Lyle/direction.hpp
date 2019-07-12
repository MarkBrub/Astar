#pragma once

namespace direction {
	enum Direction { N, NE, E, SE, S, SW, W, NW, ERROR };

	Direction getDirection(int x, int y);
};