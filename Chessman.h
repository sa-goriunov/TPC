#pragma once
#include "Global-Defines.h"
#include "Check-Defines.h"

class Chessman {
public:
	char id;
	char x;
	char y;

	bool enabled;

	Chessman(char _id, char _x, char _y) {
		id = _id;
		x = _x;
		y = _y;
		enabled = true;
	}
};