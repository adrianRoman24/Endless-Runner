#pragma once

class Fuel {
public:
	float x, y, z, lengthX, lengthY, lengthZ, value, maxValue, increase, decrease, decreaseAlways;

	Fuel(float x, float y, float z, float lengthX, float lengthY, float lengthZ, float value, float maxValue,
		float increase, float decrease, float decreaseAlways) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->lengthX = lengthX;
		this->lengthY = lengthY;
		this->lengthZ = lengthZ;
		this->value = value;
		this->maxValue = maxValue;
		this->increase = increase;
		this->decrease = decrease;
		this->decreaseAlways = decreaseAlways;
	}
};