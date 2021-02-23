# pragma once

class Pyramid {
public:
	float x, y, z, length, height, speed, scaleFactor = 1;
	bool collision = false;

	Pyramid(float x, float y, float z, float length, float height, float speed) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->length = length;
		this->height = height;
		this->speed = speed;
	}
};