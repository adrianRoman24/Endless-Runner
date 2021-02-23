#pragma once

#include "Cube.h"
#include "Diamond.h"

class Sphere {
public:
	float x, y, z, scaleFactor, radius, speed, leftLimit, rightLimit, jumpHeight;
	bool reachedHeight = false;

	Sphere(float x, float y, float z, float scaleFactor, float radius, float speed,
		float leftLimit, float rightLimit, float jumpHeight) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->scaleFactor = scaleFactor;
		this->radius = radius;
		this->speed = speed;
		this->leftLimit = leftLimit;
		this->rightLimit = rightLimit;
		this->jumpHeight = jumpHeight;
	}

	glm::vec3 Position() {
		return glm::vec3(x, y, z);
	}

	Cube* checkLand(std::list<Cube*> road) {
		for (auto it = road.begin(); it != road.end(); it++) {
			Cube *cube = *it;
			if(x <= cube->x + cube->lengthX && x >= cube->x - cube->lengthX &&
				z <= cube->z + cube->lengthZ && z >= cube->z - cube->lengthZ) {
				return cube;
			}
		}
		return NULL;
	}

	bool checkCollision(Cube *obstacle) {
		float xDistance = abs(x - obstacle->x);
		float yDistance = abs(y - obstacle->y);
		float zDistance = abs(z - obstacle->z);

		if (yDistance >= (obstacle->lengthY + radius * scaleFactor)) { return false; }
		if (zDistance >= (obstacle->lengthZ + radius * scaleFactor)) { return false; }
		if (xDistance >= (obstacle->lengthX + radius * scaleFactor)) { return false; }

		if (yDistance < (obstacle->lengthY)) { return true; }
		if (zDistance < (obstacle->lengthZ)) { return true; }
		if (xDistance < (obstacle->lengthX)) { return true; }

		float cornerDistance = (xDistance - obstacle->lengthX) * (xDistance - obstacle->lengthX) +
			(yDistance - obstacle->lengthZ) * (yDistance - obstacle->lengthZ) +
			(yDistance - obstacle->lengthY) * (yDistance - obstacle->lengthY);

		return cornerDistance < (radius * scaleFactor * radius * scaleFactor);
	}

	bool checkCollision(Diamond *diamond) {
		float xDistance = abs(x - diamond->x);
		float yDistance = abs(y - diamond->y);
		float zDistance = abs(z - diamond->z);

		if (yDistance >= (diamond->height * 2 + radius * scaleFactor)) { return false; }
		if (zDistance >= (diamond->length + radius * scaleFactor)) { return false; }
		if (xDistance >= (diamond->length + radius * scaleFactor)) { return false; }

		if (yDistance < (diamond->height * 2)) { return true; }
		if (zDistance < (diamond->length)) { return true; }
		if (xDistance < (diamond->length)) { return true; }
		
		float cornerDistance = (xDistance - diamond->length) * (xDistance - diamond->length) +
			(yDistance - diamond->length) * (yDistance - diamond->length) +
			(yDistance - diamond->height * 2) * (yDistance - diamond->height * 2);

		return cornerDistance < (radius * scaleFactor * radius * scaleFactor);
	}
};