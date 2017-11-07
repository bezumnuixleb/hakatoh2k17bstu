#pragma once
#include "Tile.h"

class Platform
{
public:
	FloatRect pos;
	bool dmg;
	Platform(float x, float y, float w, float h, int dmg) {
		pos.left = x;
		pos.top = y;
		pos.width = w;
		pos.height = h;
		if (dmg != 0) { dmg = true; }
		else { dmg = false; }
	}
	~Platform() {}
};