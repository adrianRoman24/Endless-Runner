#pragma once

#include <Component/SimpleScene.h>
#include <Core/GPU/Mesh.h>
#include "Camera.h"
#include "Sphere.h"
#include "Cube.h"
#include "Fuel.h"
#include "Torch.h"
#include "Diamond.h"
#include "Pyramid.h"

class Tema2 : public SimpleScene
{
	public:
		Tema2();
		~Tema2();

		void Init() override;


	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, Texture2D* texture);

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

		void Jump(float deltaTime);
		void DrawSphere();
		void DrawRoad();
		void DrawObstacles();
		void DrawFuel();
		void DrawLives();
		void DrawLava();
		void DrawSky();
		void DrawTorches();
		void DrawIcebergs();
		void DrawPyramids();
		void DrawDiamonds();
		void DrawScore();
		void DrawMoon();
		void UpdateRoad(float deltaTime);
		void UpdateObstacles(float deltaTime);
		void UpdateTorches(float deltaTime);
		void UpdatePyramids(float deltaTime);
		void UpdateIcebergs(float deltaTime);
		void UpdateDiamonds(float deltaTime);
		void UpdateLightPositions();
		Cube *SpawnCube(int &redCubes, float x);
		void AddPowerUp(Cube *cube);

	protected:
		// helpers
		Laborator::Camera *camera;
		glm::mat4 projectionMatrix;
		bool renderCameraTarget;
		float fov, left, right;

		// sphere
		Sphere *sphere;
		float deltaX, deltaY, deltaZ;
		float initialX, initialY, initialZ;
		bool jump;

		// road (cubes)
		std::list<Cube *> road;
		float cubeWidth, cubeHeight, cubLengthMin, cubeLengthMax;
		float minSpeed, maxSpeed, speedIncrease, speed, lastSpeed;
		float minDistanceSpawn, maxDistanceSpawn;

		// obstacles
		std::list<Cube *> obstacles;
		float obstacleWidth, obstacleHeight, obstacleLength;
		bool invincibility;
		float invincibilityDuration, invincibilityBegin;

		// fuel
		Fuel *fuel;

		// power ups
		bool landedOnRed, landedOnOrange;
		float lockSpeed, lockDuration, lockStartTime;
		bool fall;
		int deformation = 0;
		int lives, maxLives;

		// decorations
		std::list<Torch *> torches;
		std::list<Diamond *> icebergs;
		std::list<Pyramid*> pyramids;

		// bonuses
		std::list<Diamond *> diamonds;

		// score
		float score = 0, maxScore = 100;

		// textures
		std::unordered_map<std::string, Texture2D*> mapTextures;
		int applyTexture, applyColorMix;
		float lavaMovement = 0, lavaAdder = 0.02f, lavaLastTime = 0;

		// light elements
		glm::vec3 lightPosition;
		glm::vec3 lightDirection;
		unsigned int materialShininess;
		float materialKd;
		float materialKs;
		int spotlight = 0;
		int lightPosNumber = 0;
		glm::vec3 lightPositions[10];
		int spawn = 1;
};
