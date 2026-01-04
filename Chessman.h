#pragma once
#include "Global-Defines.h"
#include "Check-Defines.h"

class Chessman {
public:
	int8_t id;
	uint8_t x;

	bool enabled;

	Chessman(int8_t _id, uint8_t _x) {
		id = _id;
		x = _x;
		enabled = true;
	}
};