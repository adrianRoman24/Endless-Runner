#pragma once

class Torch {
public:
	float x, y, z, speed, fireSize, baseHeight, baseLength;

	Torch(float x, float y, float z, float fireSize, float baseHeight, float baseLength, float speed) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->fireSize = fireSize;
		this->baseHeight = baseHeight;
		this->baseLength = baseLength;
		this->speed = speed;;
	}
};