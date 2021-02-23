# pragma once

class Diamond {
public:
	float x, y, z, length, height, rotationSpeed, rotationIncrement, speed, scaleFactor = 1;
	bool collision = false;

	Diamond(float x, float y, float z, float length, float height,  float rotationSpeed, float rotationIncrement, float speed) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->length = length;
		this->height = height;
		this->rotationSpeed = rotationSpeed;
		this->rotationIncrement = rotationIncrement;
		this->speed = speed;
	}
};