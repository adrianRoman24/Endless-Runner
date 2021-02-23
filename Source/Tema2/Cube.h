#pragma once

class Cube {
public:
	float x, y, z, lengthX, lengthY, lengthZ, speed;
	std::string name;

	Cube(std::string name, float x, float y, float z, float lengthX, float lengthY, float lengthZ, float speed) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->lengthX = lengthX;
		this->lengthY = lengthY;
		this->lengthZ = lengthZ;
		this->speed = speed;
		this->name = name;
	}

	void changeName(std::string newName) {
		this->name = newName;
	}
};