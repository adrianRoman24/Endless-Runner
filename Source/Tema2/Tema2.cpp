#include "Tema2.h"

#include <vector>
#include <string>
#include <iostream>
#include "Transform3D.h"
#include "MyObject3D.h"

#include <Core/Engine.h>

#define BLUE glm::vec3(0, 0, 1)
#define RED glm::vec3(1, 0, 0)
#define YELLOW glm::vec3(0.9f, 1, 0.3f)
#define ORANGE glm::vec3(1, 0.7f, 0)
#define GREEN glm::vec3(0, 1, 0)
#define PURPLE glm::vec3(0.7f, 0, 0.9f)
#define BLACK glm::vec3(0, 0, 0)
#define WHITE glm::vec3(1, 1, 1)

using namespace std;

Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

void Tema2::DrawSphere() {
	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix = Transform3D::Scale(sphere->scaleFactor, sphere->scaleFactor, sphere->scaleFactor) * modelMatrix;
	modelMatrix = Transform3D::Translate(sphere->x, sphere->y, sphere->z) * modelMatrix;
	applyTexture = 1;
	applyColorMix = 1;
	RenderSimpleMesh(meshes["sphere"], shaders["ShaderTema2"], modelMatrix, mapTextures["ice"]);
	applyTexture = 0;
	applyColorMix = 0;
}

void Tema2::DrawRoad() {
	// draw road
	for (auto it = road.begin(); it != road.end(); it++) {
		Cube *cube = *it;
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = Transform3D::Scale(cube->lengthX, cube->lengthY, cube->lengthZ) * modelMatrix;
		modelMatrix = Transform3D::Translate(cube->x, cube->y, cube->z) * modelMatrix;
		applyTexture = 1;
		applyColorMix = 1;
		RenderSimpleMesh(meshes[cube->name], shaders["ShaderTema2"], modelMatrix, mapTextures["crate"]);
		applyTexture = 0;
		applyColorMix = 0;
	}
}

void Tema2::DrawDiamonds() {
	// draw diamonds
	for (auto it = diamonds.begin(); it != diamonds.end(); it++) {
		Diamond *diamond = *it;
		glm::mat4 modelMatrix = Transform3D::Scale(diamond->length * diamond->scaleFactor, diamond->height * diamond->scaleFactor,
			diamond->length * diamond->scaleFactor);
		modelMatrix = Transform3D::RotateOY(diamond->rotationSpeed) * modelMatrix;
		modelMatrix = Transform3D::Translate(diamond->x, diamond->y, diamond->z) * modelMatrix;
		applyTexture = 1;
		applyColorMix = 1;
		RenderSimpleMesh(meshes["pyramid"], shaders["ShaderTema2"], modelMatrix, mapTextures["ice"]);
		modelMatrix = Transform3D::Scale(diamond->length * diamond->scaleFactor, diamond->height * diamond->scaleFactor,
			diamond->length * diamond->scaleFactor);
		modelMatrix = Transform3D::RotateOY(-diamond->rotationSpeed) * modelMatrix;
		modelMatrix = Transform3D::RotateOX(RADIANS(180)) * modelMatrix;
		modelMatrix = Transform3D::Translate(diamond->x, diamond->y, diamond->z) * modelMatrix;
		RenderSimpleMesh(meshes["pyramid"], shaders["ShaderTema2"], modelMatrix, mapTextures["ice"]);
		applyTexture = 0;
		applyColorMix = 0;
	}
}

void Tema2::DrawIcebergs() {
	// draw icebergs
	for (auto it = icebergs.begin(); it != icebergs.end(); it++) {
		Diamond *diamond = *it;
		glm::mat4 modelMatrix = Transform3D::Scale(diamond->length * diamond->scaleFactor, diamond->height * diamond->scaleFactor,
			diamond->length * diamond->scaleFactor);
		modelMatrix = Transform3D::RotateOY(diamond->rotationSpeed) * modelMatrix;
		modelMatrix = Transform3D::Translate(diamond->x, diamond->y, diamond->z) * modelMatrix;
		applyTexture = 1;
		applyColorMix = 1;
		RenderSimpleMesh(meshes["pyramid"], shaders["ShaderTema2"], modelMatrix, mapTextures["ice"]);
		modelMatrix = Transform3D::Scale(diamond->length * diamond->scaleFactor, diamond->height * diamond->scaleFactor,
			diamond->length * diamond->scaleFactor);
		modelMatrix = Transform3D::RotateOY(-diamond->rotationSpeed) * modelMatrix;
		modelMatrix = Transform3D::RotateOX(RADIANS(180)) * modelMatrix;
		modelMatrix = Transform3D::Translate(diamond->x, diamond->y, diamond->z) * modelMatrix;
		RenderSimpleMesh(meshes["pyramid"], shaders["ShaderTema2"], modelMatrix, mapTextures["ice"]);
		applyTexture = 0;
		applyColorMix = 0;
	}
}

void Tema2::DrawPyramids() {
	// draw pyramids
	for (auto it = pyramids.begin(); it != pyramids.end(); it++) {
		Pyramid *pyramid = *it;
		glm::mat4 modelMatrix = Transform3D::Scale(pyramid->length * pyramid->scaleFactor, pyramid->height * pyramid->scaleFactor,
			pyramid->length * pyramid->scaleFactor);
		modelMatrix = Transform3D::Translate(pyramid->x, pyramid->y, pyramid->z) * modelMatrix;
		applyTexture = 1;
		applyColorMix = 1;
		RenderSimpleMesh(meshes["pyramid"], shaders["ShaderTema2"], modelMatrix, mapTextures["ice"]);
		applyTexture = 0;
		applyColorMix = 0;
	}
}

void Tema2::DrawTorches() {
	applyTexture = 1;
	applyColorMix = 1;
	// draw torches
	for (auto it = torches.begin(); it != torches.end(); it++) {
		Torch *torch = *it;
		// draw fire
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = Transform3D::Scale(torch->baseLength, torch->baseHeight, torch->baseLength) * modelMatrix;
		modelMatrix = Transform3D::Translate(torch->x, torch->y - torch->baseHeight, torch->z) * modelMatrix;
		RenderSimpleMesh(meshes["whiteCube"], shaders["ShaderTema2"], modelMatrix, mapTextures["crate"]);
		modelMatrix = glm::mat4(1);
		modelMatrix = Transform3D::Scale(torch->fireSize, torch->fireSize, torch->fireSize) * modelMatrix;
		modelMatrix = Transform3D::Translate(torch->x, torch->y + torch->fireSize, torch->z) * modelMatrix;
		RenderSimpleMesh(meshes["whiteCube"], shaders["ShaderTema2"], modelMatrix, mapTextures["ice"]);
	}
	applyColorMix = 0;
	applyTexture = 0;
}

void Tema2::DrawObstacles() {
	// draw obstacles
	for (auto it = obstacles.begin(); it != obstacles.end(); it++) {
		Cube *cube = *it;
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = Transform3D::Scale(cube->lengthX, cube->lengthY, cube->lengthZ) * modelMatrix;
		modelMatrix = Transform3D::Translate(cube->x, cube->y, cube->z) * modelMatrix;
		applyTexture = 1;
		applyColorMix = 1;
		RenderSimpleMesh(meshes[cube->name], shaders["ShaderTema2"], modelMatrix, mapTextures["stone"]);
		applyTexture = 0;
		applyColorMix = 0;
	}
}

void Tema2::DrawFuel() {
	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix = Transform3D::Scale(fuel->lengthX * 0.9f * fuel->value / fuel->maxValue, fuel->lengthY * 0.9f, 0) * modelMatrix;
	modelMatrix = Transform3D::RotateOX(-0.2f) * modelMatrix;
	modelMatrix = Transform3D::Translate(fuel->x, fuel->y, fuel->z + 0.01f) * modelMatrix;
	modelMatrix = Transform3D::Translate(- 0.9f * (fuel->lengthX - fuel->lengthX * fuel->value / fuel->maxValue),
		0, 0) * modelMatrix;
	RenderMesh(meshes["blackCube"], shaders["ShaderTema2"], modelMatrix);
	modelMatrix = glm::mat4(1);
	modelMatrix = Transform3D::Scale(fuel->lengthX, fuel->lengthY, 0) * modelMatrix;
	modelMatrix = Transform3D::RotateOX(-0.2f) * modelMatrix;
	modelMatrix = Transform3D::Translate(fuel->x, fuel->y, fuel->z) * modelMatrix;
	RenderMesh(meshes["blueCube"], shaders["ShaderTema2"], modelMatrix);
	applyColorMix = 0;
	applyTexture = 0; 
}

void Tema2::DrawScore() {
	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix = Transform3D::Scale(fuel->lengthX * 0.9f * score / maxScore, fuel->lengthY * 0.9f, 0) * modelMatrix;
	modelMatrix = Transform3D::RotateOX(-0.2f) * modelMatrix;
	modelMatrix = Transform3D::Translate(fuel->x + 2, fuel->y + 0.1f, fuel->z + 0.01f) * modelMatrix;
	modelMatrix = Transform3D::Translate(-0.9f * (fuel->lengthX - fuel->lengthX * score / maxScore),
		0, 0) * modelMatrix;
	RenderMesh(meshes["redCube"], shaders["ShaderTema2"], modelMatrix);
	modelMatrix = glm::mat4(1);
	modelMatrix = Transform3D::Scale(fuel->lengthX, fuel->lengthY * 1.2f, 0) * modelMatrix;
	modelMatrix = Transform3D::RotateOX(-0.2f) * modelMatrix;
	modelMatrix = Transform3D::Translate(fuel->x + 2, fuel->y + 0.1f, fuel->z) * modelMatrix;
	RenderMesh(meshes["blackCube"], shaders["ShaderTema2"], modelMatrix);
	applyColorMix = 0;
	applyTexture = 0;
}

void Tema2::DrawLives() {
	for (int i = 0; i < lives; i++) {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = Transform3D::Scale(0.05f, 0.05f, 0) * modelMatrix;
		modelMatrix = Transform3D::RotateOX(-0.2f) * modelMatrix;
		modelMatrix = Transform3D::Translate(-1.21f + 4 * i * 0.05f, 1.88f, 1) * modelMatrix;
		RenderMesh(meshes["redCube"], shaders["ShaderTema2"], modelMatrix);
	}
}

void Tema2::DrawLava() {
	float scaleFactor = 10;
	if ((int)Engine::GetElapsedTime() - lavaLastTime >= 5) {
		lavaAdder = -lavaAdder;
		lavaLastTime = (float)Engine::GetElapsedTime();
	}
	lavaMovement += lavaAdder;
	applyTexture = 1;
	for (float z = 0; z > -scaleFactor * 2 * 3; z -= scaleFactor) {
		for (float x = -scaleFactor * 2 * 4; x <= scaleFactor * 2 * 4; x += scaleFactor) {
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = Transform3D::Scale(scaleFactor, scaleFactor, scaleFactor) * modelMatrix;
			modelMatrix = Transform3D::RotateOX(RADIANS(-90)) * modelMatrix;
			modelMatrix = Transform3D::Translate(x + lavaMovement, -1.3f, z) * modelMatrix;
			RenderSimpleMesh(meshes["square"], shaders["ShaderTema2"], modelMatrix, mapTextures["lava"]);
		}
	}
	applyTexture = 0;
}

void Tema2::DrawSky() {
	float scaleFactor = 80;
	applyTexture = 1;
	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix = Transform3D::Scale(scaleFactor * 4.5f, scaleFactor * 2, scaleFactor) * modelMatrix;
	modelMatrix = Transform3D::Translate(0, 7, -scaleFactor * 2) * modelMatrix;
	RenderSimpleMesh(meshes["square"], shaders["ShaderTema2"], modelMatrix, mapTextures["sky"]);
	applyTexture = 0;
}

void Tema2::DrawMoon() {
	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix = Transform3D::Scale(8, 8, 0.1f) * modelMatrix;
	modelMatrix = Transform3D::RotateOX(RADIANS(-20)) * modelMatrix;
	modelMatrix = Transform3D::Translate(0, 7, -40) * modelMatrix;
	applyTexture = 1;
	RenderSimpleMesh(meshes["moon"], shaders["ShaderTema2"], modelMatrix, mapTextures["sharingan"]);
	applyTexture = 0;
}

Cube* Tema2::SpawnCube(int &redCubes, float x) {
	float random = cubLengthMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX /
		(cubeLengthMax - cubLengthMin)));
	int colorCode = rand() % 10;
	switch (colorCode) {
	case 0:
		return new Cube("blueCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	case 1:
		return new Cube("blueCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	case 2:
		return new Cube("blueCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	case 3:
		return new Cube("greenCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	case 4:
		return new Cube("greenCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	case 5:
		return new Cube("yellowCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	case 6:
		return new Cube("yellowCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	case 7:
		return new Cube("orangeCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	case 8:
		return new Cube("whiteCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	default:
		return new Cube("redCube", x, -0.25f, -25.0f, cubeWidth, cubeHeight, random, speed);
		break;
	}
	return NULL;
}

void Tema2::AddPowerUp(Cube *cube) {
	if (cube->name == "redCube") {
		landedOnRed = true;
	} else if(cube->name == "yellowCube") {
		cout << "FUEL LOSS!" << endl;
		fuel->value = max(0.0f, fuel->value - fuel->increase);
	} else if(cube->name == "greenCube") {
		cout << "FUEL BOOST!" << endl;
		fuel->value = min(100.0f, fuel->value + fuel->increase);
	} else if (cube->name == "orangeCube") {
		cout << "SPEED LOCK! DURATION: 4 seconds" << endl;
		lockStartTime = (float)Engine::GetElapsedTime();
		if (!landedOnOrange) {
			lastSpeed = speed;
		}
		landedOnOrange = true;
		speed = lockSpeed;
		for (auto it = road.begin(); it != road.end(); it++) {
			(*it)->speed = speed;
		}
		for (auto it = obstacles.begin(); it != obstacles.end(); it++) {
			(*it)->speed = speed;
		}
		for (auto it = torches.begin(); it != torches.end(); it++) {
			(*it)->speed = speed;
		}
		for (auto it = diamonds.begin(); it != diamonds.end(); it++) {
			(*it)->speed = speed;
		}
		for (auto it = icebergs.begin(); it != icebergs.end(); it++) {
			(*it)->speed = speed;
		}
		for (auto it = pyramids.begin(); it != pyramids.end(); it++) {
			(*it)->speed = speed;
		}
	} else if(cube->name == "whiteCube") {
		lives = min(lives + 1, maxLives);
		invincibility = true;
		cout << "INVINCIBILITY ACTIVATED! DURATION: 4 SECONDS" << endl;
		invincibilityBegin = (float)Engine::GetElapsedTime();
	}
}

void Tema2::UpdateRoad(float deltaTime) {
	// move
	for (auto it = road.begin(); it != road.end(); it++) {
		Cube *cube = *it;
		cube->z += cube->speed * deltaTime;
	}

	// delete
	auto it = road.begin();
	while (it != road.end()) {
		Cube *cube = *it;
		if (cube->z - cube->lengthZ > camera->position.z) {
			road.erase(it++);
		}
		else {
			++it;
		}
	}

	// spawn road, obstacle on road and diamonds on road
	float randomDistanceSpawn = minDistanceSpawn + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX /
		(maxDistanceSpawn - minDistanceSpawn)));
	if (road.back()->z - road.back()->lengthZ - randomDistanceSpawn > -25.0f) {
		int redCubes = 0;
		int newObstacle = rand() % 4;
		road.push_back(SpawnCube(redCubes, sphere->rightLimit));
		if (newObstacle == 1) {
			Cube *lastCube = road.back();
			obstacles.push_back(new Cube("redCube", lastCube->x, lastCube->y + cubeHeight + obstacleHeight, lastCube->z,
				obstacleWidth, obstacleHeight, obstacleLength, lastCube->speed));
		} else if (rand() % 2 == 1) {
			Cube *lastCube = road.back();
			diamonds.push_back(new Diamond(lastCube->x, lastCube->y + 0.8f, lastCube->z, 0.2f, 0.5f, 0, 10, speed));
		}
		// - lastCube->lengthZ + obstacleLength 
		road.push_back(SpawnCube(redCubes, 0));
		if (newObstacle == 2) {
			Cube *lastCube = road.back();
			obstacles.push_back(new Cube("redCube", lastCube->x, lastCube->y + cubeHeight + obstacleHeight, lastCube->z,
				obstacleWidth, obstacleHeight, obstacleLength, lastCube->speed));
		} else if (rand() % 2 == 1) {
			Cube *lastCube = road.back();
			diamonds.push_back(new Diamond(lastCube->x, lastCube->y + 0.8f, lastCube->z, 0.2f, 0.5f, 0, 10, speed));
		}
		road.push_back(SpawnCube(redCubes, sphere->leftLimit));
		if (newObstacle == 3) {
			Cube *lastCube = road.back();
			obstacles.push_back(new Cube("redCube", lastCube->x, lastCube->y + cubeHeight + obstacleHeight, lastCube->z,
				obstacleWidth, obstacleHeight, obstacleLength, lastCube->speed));
		} else if (rand() % 2 == 1) {
			Cube *lastCube = road.back();
			diamonds.push_back(new Diamond(lastCube->x, lastCube->y + 0.8f, lastCube->z, 0.2f, 0.5f, 0, 10, speed));
		}
	}
}

void Tema2::UpdateObstacles(float deltaTime) {
	// move
	for (auto it = obstacles.begin(); it != obstacles.end(); it++) {
		Cube *cube = *it;
		cube->z += cube->speed * deltaTime;
	}

	// delete
	auto it = obstacles.begin();
	while (it != obstacles.end()) {
		Cube *cube = *it;
		if (cube->z - cube->lengthZ > camera->position.z) {
			obstacles.erase(it++);
		}
		else {
			++it;
		}
	}

	// check sphere collision
	for (auto it = obstacles.begin(); it != obstacles.end(); it++) {
		Cube *cube = *it;
		if (sphere->checkCollision(cube)) {
			if (!invincibility) {
				cout << "COLIISION!" << endl;
				fall = true;
			}
		}
	}
}

void Tema2::UpdateTorches(float deltaTime) {
	// move
	for (auto it = torches.begin(); it != torches.end(); it++) {
		Torch *torch = *it;
		torch->z += torch->speed * deltaTime;
	}

	// delete
	auto it = torches.begin();
	while (it != torches.end()) {
		Torch *torch = *it;
		if (torch->z - torch->fireSize > camera->position.z) {
			torches.erase(it++);
		}
		else {
			++it;
		}
	}

	// spawn
	float randomDistanceSpawn = minDistanceSpawn;
	if (torches.back()->z - road.back()->lengthZ - randomDistanceSpawn > -25.0f) {
		torches.push_back(new Torch(-7, 0.5f, -25.0f, 0.5f, 1, 0.2f, speed));
		torches.push_back(new Torch(7, 0.5f, -25.0f, 0.5f, 1, 0.2f, speed));
	}
}

void Tema2::UpdateIcebergs(float deltaTime) {
	// move
	for (auto it = icebergs.begin(); it != icebergs.end(); it++) {
		Diamond *diamond = *it;
		diamond->z += diamond->speed * deltaTime;
		diamond->rotationSpeed += diamond->rotationIncrement * deltaTime;
	}

	// delete
	auto it = icebergs.begin();
	while (it != icebergs.end()) {
		Diamond *diamond = *it;
		if (diamond->z - diamond->length > camera->position.z) {
			icebergs.erase(it++);
		}
		else {
			++it;
		}
	}

	// spawn
	float randomDistanceSpawn = minDistanceSpawn;
	if (icebergs.back()->z - road.back()->lengthZ - randomDistanceSpawn - 10 > -25.0f) {
		if (spawn == 1) {
			icebergs.push_back(new Diamond(-7, 3, -25.0f, 1.5f, 2.5f, 0, 3, speed));
			icebergs.push_back(new Diamond(7, 3, -25.0f, 1.5f, 2.5f, 0, 3, speed));
		} else {
			icebergs.push_back(new Diamond(0, 5, -25.0f, 1.5f, 2.5f, 0, 3, speed));
		}
		spawn = 1 - spawn;
	}
}

void Tema2::UpdatePyramids(float deltaTime) {
	// move
	for (auto it = pyramids.begin(); it != pyramids.end(); it++) {
		Pyramid *pyramid = *it;
		pyramid->z += pyramid->speed * deltaTime;
	}

	// delete
	auto it = pyramids.begin();
	while (it != pyramids.end()) {
		Pyramid *pyramid = *it;
		if (pyramid->z - pyramid->length > camera->position.z) {
			pyramids.erase(it++);
		}
		else {
			++it;
		}
	}

	// spawn
	float randomDistanceSpawn = minDistanceSpawn;
	if (pyramids.back()->z - road.back()->lengthZ - randomDistanceSpawn > -25.0f) {
		pyramids.push_back(new Pyramid(-12, -1, -30.0f, 3, 6, speed));
		pyramids.push_back(new Pyramid(12, -1, -30.0f, 3, 6, speed));
	}
}

void Tema2::UpdateDiamonds(float deltaTime) {
	// move
	for (auto it = diamonds.begin(); it != diamonds.end(); it++) {
		Diamond *diamond = *it;
		diamond->z += diamond->speed * deltaTime;
		diamond->rotationSpeed += diamond->rotationIncrement * deltaTime;
	}

	// delete
	auto it = diamonds.begin();
	while (it != diamonds.end()) {
		Diamond *diamond = *it;
		if (diamond->z - diamond->length > camera->position.z) {
			diamonds.erase(it++);
		}
		else {
			++it;
		}
	}

	// check sphere collision and scale factor
	for (auto it = diamonds.begin(); it != diamonds.end(); it++) {
		Diamond *diamond = *it;
		if (sphere->checkCollision(diamond) && diamond->collision == false) {
			score = min(maxScore, score + 2);
			cout << "SCORE = " << score << endl;
			diamond->collision = true;
		}
		if (diamond->collision == true) {
			diamond->scaleFactor = MAX(0, diamond->scaleFactor - 0.05f);
			if (diamond->scaleFactor < 0)
				diamond->scaleFactor = 0;
		}
	}
}

void Tema2::UpdateLightPositions() {
	lightPosNumber = 0;
	for (auto it = icebergs.begin(); it != icebergs.end(); it++) {
		lightPositions[lightPosNumber].x = (*it)->x;
		if((*it)->y != 0)
			lightPositions[lightPosNumber].y = (*it)->y;
		else {
			lightPositions[lightPosNumber].y = (*it)->y - (*it)->height;
		}
		lightPositions[lightPosNumber].z = (*it)->z;
		lightPosNumber++;
	}
}

void Tema2::Init()
{
	// Textures
	applyTexture = 0;
	applyColorMix = 0;
	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/sharingan.jpg", GL_REPEAT);
		mapTextures["sharingan"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/fire.jpg", GL_REPEAT);
		mapTextures["fire"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/sky.jpg", GL_REPEAT);
		mapTextures["sky"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/lava.jpg", GL_REPEAT);
		mapTextures["lava"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/stone.jpg", GL_REPEAT);
		mapTextures["stone"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/concrete.png", GL_REPEAT);
		mapTextures["concrete"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/crate.jpg", GL_REPEAT);
		mapTextures["crate"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/ice.jpg", GL_REPEAT);
		mapTextures["ice"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Textures/grass_bilboard.png", GL_REPEAT);
		mapTextures["grass"] = texture;
	}
	// Create a simple quad
	{
		vector<glm::vec3> vertices
		{
			glm::vec3(0.5f,   0.5f, 0.0f),	// Top Right
			glm::vec3(0.5f,  -0.5f, 0.0f),	// Bottom Right
			glm::vec3(-0.5f, -0.5f, 0.0f),	// Bottom Left
			glm::vec3(-0.5f,  0.5f, 0.0f),	// Top Left
		};

		vector<glm::vec3> normals
		{
			glm::vec3(0, 1, 1),
			glm::vec3(1, 0, 1),
			glm::vec3(1, 0, 0),
			glm::vec3(0, 1, 0)
		};

		vector<glm::vec2> textureCoords
		{
			glm::vec2(1, 0),
			glm::vec2(1, 1),
			glm::vec2(0, 1),
			glm::vec2(0, 0),
		};

		vector<unsigned short> indices =
		{
			0, 1, 3,
			1, 2, 3
		};

		Mesh* mesh = new Mesh("square");
		mesh->InitFromData(vertices, normals, textureCoords, indices);
		meshes[mesh->GetMeshID()] = mesh;
	}
	// helpers
	jump = false;
	landedOnRed = false;
	landedOnOrange = false;
	lockSpeed = 9;
	lockDuration = 3; // seconds
	lockStartTime = -1; // uninitialized
	fall = false;

	// create cube
	cubeHeight = 0.25f;
	cubeWidth = 0.5f;
	cubeLengthMax = 3.5f;
	cubLengthMin = 2.5f;
	minSpeed = 6;
	speed = 6;
	lastSpeed = speed;
	speedIncrease = 5;
	maxSpeed = 10;
	minDistanceSpawn = 4.8f;
	maxDistanceSpawn = 5.2f;
	AddMeshToList(MyObject3D::CreateCube("blueCube", BLUE));
	AddMeshToList(MyObject3D::CreateCube("redCube", RED));
	AddMeshToList(MyObject3D::CreateCube("yellowCube", YELLOW));
	AddMeshToList(MyObject3D::CreateCube("orangeCube", ORANGE));
	AddMeshToList(MyObject3D::CreateCube("greenCube", GREEN));
	AddMeshToList(MyObject3D::CreateCube("purpleCube", PURPLE));
	AddMeshToList(MyObject3D::CreateCube("blackCube", BLACK));
	AddMeshToList(MyObject3D::CreateCube("whiteCube", WHITE));

	AddMeshToList(MyObject3D::CreatePyramid("pyramid", WHITE));

	// obstacles
	obstacleHeight = 0.75f;
	obstacleWidth = 0.5f;
	obstacleLength = 0.2f;
	invincibility = false;
	invincibilityDuration = 4;

	// create sphere
	Mesh* mesh = new Mesh("sphere");
	mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
	meshes[mesh->GetMeshID()] = mesh;
	float sphereRadius = 0.5f;
	float sphereScale = 0.6f;
	float sphereLimit = sphereRadius * 6;
	float jumpHeight = sphereRadius * 5;
	initialX = 0;
	initialY = sphereRadius * sphereScale;
	initialZ = sphereRadius;
	sphere = new Sphere(initialX, initialY, initialZ, sphereScale,
		sphereRadius, window->GetResolution().x / 200.0f, -sphereLimit, sphereLimit, jumpHeight);
	// add sphere initial land
	road.push_back(new Cube("blueCube", sphere->x, -0.25f, sphere->z, cubeWidth, cubeHeight, sphere->radius * 42, speed));

	// first spawn
	int redCubes = 0;
	road.push_back(SpawnCube(redCubes, sphere->rightLimit));
	road.push_back(SpawnCube(redCubes, 0));
	road.push_back(SpawnCube(redCubes, sphere->leftLimit));
	deformation = 0;

	// moon
	{
		Mesh* mesh = new Mesh("moon");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	// first decorations spawn
	torches.push_back(new Torch(-7, 0.5f, -25.0f, 0.5f, 1, 0.2f, speed));
	torches.push_back(new Torch(7, 0.5f, -25.0f, 0.5f, 1, 0.2f, speed));
	icebergs.push_back(new Diamond(-7, 3, -25.0f, 1.5f, 2.5f, 0, 3, speed));
	icebergs.push_back(new Diamond(7, 3, -25.0f, 1.5f, 2.5f, 0, 3, speed));
	icebergs.push_back(new Diamond(0, 5, -25.0f, 1.5f, 2.5f, 0, 3, speed));
	pyramids.push_back(new Pyramid(-12, -1, -30, 3, 6, speed));
	pyramids.push_back(new Pyramid(12, -1, -30, 3, 6, speed));

	// create camera
	renderCameraTarget = true;
	deltaX = 0;
	deltaY = 1.5f;
	deltaZ = 4;
	camera = new Laborator::Camera();
	camera->Set(glm::vec3(deltaX + sphere->x, sphere->y + deltaY, sphere->z + deltaZ), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	camera->RotateFirstPerson_OX(0.3f);

	// create fuel
	fuel = new Fuel(-1, 1.7f, 1, 0.3f, 0.05f, 0.01f, 100, 100, 20, 40, 0.1f);

	// create lives
	maxLives = 5;
	lives = 3;

	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader *shader = new Shader("ShaderTema2");
		shader->AddShader("Source/Tema2/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Tema2/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	fov = RADIANS(60);
	left = -15;
	right = 15;
	projectionMatrix = glm::perspective(fov, window->props.aspectRatio, 0.01f, 200.0f);
	cout << "START WITH 3 LIVES" << endl;

	//Light & material properties
	{
		lightPosition = glm::vec3(0, 1, 0);
		lightDirection = glm::vec3(0, -1, 0);
		materialShininess = 30;
		materialKd = 0.5;
		materialKs = 0.5;
	}
}


void Tema2::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::Jump(float deltaTime) {
	if (sphere->reachedHeight) {
		sphere->y -= sphere->speed * deltaTime;
		if (!renderCameraTarget) {
			camera->TranslateUpword(-sphere->speed * deltaTime);
		}
	}
	else {
		sphere->y += sphere->speed * deltaTime;
		if (!renderCameraTarget) {
			camera->TranslateUpword(sphere->speed * deltaTime);
		}
	}
	if (sphere->y > sphere->jumpHeight) {
		sphere->reachedHeight = true;
		sphere->y = sphere->jumpHeight;
		if (!renderCameraTarget) {
			camera->position.y = sphere->jumpHeight;
		}
	}
	if (sphere->y < initialY) {
		sphere->y = initialY;
		jump = false;
		if (!renderCameraTarget) {
			camera->position.y = sphere->radius * sphere->scaleFactor;
		}
	}
}

void Tema2::Update(float deltaTimeSeconds)
{
	// GREEN = OY
	// BLUE = OZ
	// RED = OX

	// Update light positions
	UpdateLightPositions();

	// draw floor (lava)
	DrawLava();

	if (fall) {
		// draw obstacles
		DrawObstacles();

		// draw road
		DrawRoad();

		// draw diamonds
		DrawDiamonds();

		// draw decorations
		DrawTorches();
		DrawIcebergs();
		DrawMoon();
		DrawPyramids();

		// draw sphere
		if (renderCameraTarget)
		{
			DrawSphere();
		}
		if (sphere->scaleFactor <= 0) {
			sphere->scaleFactor = 0;
		}
		sphere->scaleFactor -= 0.01f;
		DrawSky();
		return;
	}

	// check if jump
	if (!jump) {
		Cube *landedCube = sphere->checkLand(road);
		// check if fall
		if (landedCube == NULL) {
			cout << "FALL!" << endl;
			fall = true;
		}
		// add power ups
		if (landedCube != NULL) {
			AddPowerUp(landedCube);
			landedCube->changeName("purpleCube");
		}
	} else if (!renderCameraTarget) {
		if (camera->position.y < sphere->radius * sphere->scaleFactor) {
			camera->position.y = sphere->radius * sphere->scaleFactor + sphere->y;
		}
	}
	// check if landed on red
	if (landedOnRed) {
		cout << "LANDED ON RED ROAD!" << endl;
		lives--;
		if (lives == 0) {
			fall = true;
			cout << "NO MORE LIVES!" << endl;
		}
		landedOnRed = false;
	}

	// check if lock speed is over
	if (landedOnOrange) {
		if ((float)Engine::GetElapsedTime() - lockStartTime >= lockDuration) {
			cout << "SPEED UNLOCK!" << endl;
			speed = lastSpeed;
			landedOnOrange = false;
			for (auto it = road.begin(); it != road.end(); it++) {
				(*it)->speed = speed;
			}
			for (auto it = obstacles.begin(); it != obstacles.end(); it++) {
				(*it)->speed = speed;
			}
			for (auto it = torches.begin(); it != torches.end(); it++) {
				(*it)->speed = speed;
			}
			for (auto it = diamonds.begin(); it != diamonds.end(); it++) {
				(*it)->speed = speed;
			}
			for (auto it = icebergs.begin(); it != icebergs.end(); it++) {
				(*it)->speed = speed;
			}
			for (auto it = pyramids.begin(); it != pyramids.end(); it++) {
				(*it)->speed = speed;
			}
		}
	}
	
	// draw obstacles
	DrawObstacles();

	// draw road
	DrawRoad();

	// draw fuel
	DrawFuel();

	// draw score
	DrawScore();

	// draw lives
	DrawLives();

	// draw diamonds
	DrawDiamonds();

	// draw decorations
	DrawTorches();
	DrawIcebergs();
	DrawMoon();
	DrawPyramids();

	// draw sphere
	if (renderCameraTarget)
	{
		DrawSphere();
	}

	// draw sky
	DrawSky();

	// update fuel
	fuel->value -= fuel->decreaseAlways;
	if (fuel->value <= 0) {
		cout << "OUT OF FUEL!" << endl;
		lives--;
		cout << lives << " MORE LIVES!" << endl;
		if (lives == 0) {
			fall = true;
		}
		else {
			fuel->value = fuel->maxValue;
		}
	}

	// update road
	UpdateRoad(deltaTimeSeconds);

	// update diamonds
	UpdateDiamonds(deltaTimeSeconds);

	// update decorations
	UpdateTorches(deltaTimeSeconds);
	UpdateIcebergs(deltaTimeSeconds);
	UpdatePyramids(deltaTimeSeconds);

	// update Obstacles
	UpdateObstacles(deltaTimeSeconds);

	// update invincibility
	if (invincibility && Engine::GetElapsedTime() - invincibilityBegin >= invincibilityDuration) {
		cout << "INVINCIBILITY DEACTIVATED" << endl;
		invincibility = false;
	}

	// sphere jump
	if (jump) {
		Jump(deltaTimeSeconds);
	}
}

void Tema2::FrameEnd()
{
	//DrawCoordinatSystem(camera->GetViewMatrix(), projectionMatrix);
}

void Tema2::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, Texture2D* texture)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	//int light_position = glGetUniformLocation(shader->program, "light_position");
	//glUniform3f(light_position, lightPosition.x, lightPosition.y, lightPosition.z);

	int light_positions = glGetUniformLocation(shader->program, "light_positions");
	glUniform3fv(light_positions, 10, reinterpret_cast<GLfloat *>(lightPositions));

	int light_direction = glGetUniformLocation(shader->program, "light_direction");
	glUniform3f(light_direction, lightDirection.x, lightDirection.y, lightDirection.z);

	// TODO: Set eye position (camera position) uniform
	glm::vec3 eyePosition = camera->position;
	int eye_position = glGetUniformLocation(shader->program, "eye_position");
	glUniform3f(eye_position, eyePosition.x, eyePosition.y, eyePosition.z);

	// TODO: Set material property uniforms (shininess, kd, ks, object color) 
	int material_shininess = glGetUniformLocation(shader->program, "material_shininess");
	glUniform1i(material_shininess, materialShininess);

	int lightPosNumberLocation = glGetUniformLocation(shader->program, "lightPosNumber");
	glUniform1i(lightPosNumberLocation, lightPosNumber);


	int material_kd = glGetUniformLocation(shader->program, "material_kd");
	glUniform1f(material_kd, materialKd);

	int material_ks = glGetUniformLocation(shader->program, "material_ks");
	glUniform1f(material_ks, materialKs);

	int spotlight_location = glGetUniformLocation(shader->program, "spotlight");
	glUniform1i(spotlight_location, spotlight);

	// TODO : get shader location for uniform mat4 "Model"
	int location = glGetUniformLocation(shader->program, "Model");

	// TODO : set shader uniform "Model" to modelMatrix
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// TODO : get shader location for uniform mat4 "View"
	location = glGetUniformLocation(shader->program, "View");

	// TODO : set shader uniform "View" to viewMatrix
	glm::mat4 viewMatrix = camera->GetViewMatrix();
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// TODO : get shader location for uniform mat4 "Projection"
	location = glGetUniformLocation(shader->program, "Projection");

	// TODO : set shader uniform "Projection" to projectionMatrix
	//glm::mat4 projectionMatrix = projectionMatrix;
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	if (texture != NULL) {
		//TODO : activate texture location 0
		glActiveTexture(GL_TEXTURE0);
		//TODO : Bind the texture1 ID
		glBindTexture(GL_TEXTURE_2D, texture->GetTextureID());
		//TODO : Send texture uniform value
		glUniform1i(glGetUniformLocation(shader->program, "texture"), 0);
	}

	// BONUS
	location = glGetUniformLocation(shader->program, "Time");
	float time = (float)Engine::GetElapsedTime();
	glUniform1f(location, time);
	//cout << time << endl;
	location = glGetUniformLocation(shader->program, "Deformation");
	glUniform1i(location, deformation);
	location = glGetUniformLocation(shader->program, "applyTexture");
	glUniform1i(location, applyTexture);
	location = glGetUniformLocation(shader->program, "applyColorMix");
	glUniform1i(location, applyColorMix);

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
	if (fall) {
		return;
	}
	// add press key event
	if (window->KeyHold(GLFW_KEY_A)){
		sphere->x -= sphere->speed * deltaTime;
		if (sphere->x < sphere->leftLimit) {
			sphere->x = sphere->leftLimit;
			if (!renderCameraTarget) {
				camera->position.x = sphere->leftLimit;
			}
		} else if (!renderCameraTarget) {
			camera->TranslateRight(-sphere->speed * deltaTime);
		}
	}
	if (window->KeyHold(GLFW_KEY_D)) {
		sphere->x += sphere->speed * deltaTime;
		if (sphere->x > sphere->rightLimit) {
			sphere->x = sphere->rightLimit;
			if (!renderCameraTarget) {
				camera->position.x = sphere->rightLimit;
			}
		} else if (!renderCameraTarget) {
			camera->TranslateRight(sphere->speed * deltaTime);
		}
	}
	if (!landedOnOrange) {
		if (window->KeyHold(GLFW_KEY_W)) {
			if (speed + speedIncrease * deltaTime <= maxSpeed) {
				speed += speedIncrease * deltaTime;
				for (auto it = road.begin(); it != road.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = obstacles.begin(); it != obstacles.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = torches.begin(); it != torches.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = diamonds.begin(); it != diamonds.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = icebergs.begin(); it != icebergs.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = pyramids.begin(); it != pyramids.end(); it++) {
					(*it)->speed = speed;
				}
			}
		}
		lastSpeed = speed;
	}
	if (!landedOnOrange) {
		if (window->KeyHold(GLFW_KEY_S)) {
			if (speed - speedIncrease * deltaTime >= minSpeed) {
				speed -= speedIncrease * deltaTime;
				for (auto it = road.begin(); it != road.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = obstacles.begin(); it != obstacles.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = torches.begin(); it != torches.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = diamonds.begin(); it != diamonds.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = icebergs.begin(); it != icebergs.end(); it++) {
					(*it)->speed = speed;
				}
				for (auto it = pyramids.begin(); it != pyramids.end(); it++) {
					(*it)->speed = speed;
				}
			}
		}
		lastSpeed = speed;
	}
}

void Tema2::OnKeyPress(int key, int mods)
{
	// add key press event
	// change mode to first person
	if (key == GLFW_KEY_C)
	{
		if (renderCameraTarget) {
			// third person to first person
			camera->TranslateForward(deltaZ);
			camera->TranslateUpword(initialY - deltaY);
			camera->TranslateRight(sphere->x);
			renderCameraTarget = false;
		}
		else {
			// first person to third person
			camera->Set(glm::vec3(deltaX + initialX, initialY + deltaY, initialZ + deltaZ), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			camera->RotateFirstPerson_OX(0.3f);
			renderCameraTarget = true;
		}
	}
	if (fall) {
		return;
	}
	if (key == GLFW_KEY_SPACE && !jump) {
		jump = true;
		sphere->reachedHeight = false;
	}
}

void Tema2::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}
