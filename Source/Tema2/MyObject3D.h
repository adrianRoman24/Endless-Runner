#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>
#include <Core/Engine.h>
#include <vector>

constexpr auto PI = 3.141592653589793f;

namespace MyObject3D
{
	Mesh* CreateMesh(std::string name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned short> &indices)
	{
		unsigned int VAO = 0;
		// TODO: Create the VAO and bind it
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		// TODO: Create the VBO and bind it
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		// TODO: Send vertices data into the VBO buffer
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

		// TODO: Create the IBO and bind it
		unsigned int IBO;
		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		// TODO: Send indices data into the IBO buffer
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

		// ========================================================================
		// This section describes how the GPU Shader Vertex Shader program receives data

		// set vertex position attribute
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

		// set vertex normal attribute
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

		// set texture coordinate attribute
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

		// set vertex color attribute
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));

		// ========================================================================

		// Unbind the VAO
		glBindVertexArray(0);

		// Check for OpenGL errors
		CheckOpenGLError();

		// Mesh information is saved into a Mesh object
		Mesh *mesh = new Mesh(name);
		mesh->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
		mesh->vertices = vertices;
		mesh->indices = indices;
		return mesh;
	}

	Mesh* CreateCube(std::string name, glm::vec3 color) {

		// Create a simple cube
		
			std::vector<VertexFormat> vertices
			{
				// 0
				VertexFormat(glm::vec3(-1, -1,  1), color, glm::vec3(0, 0, 1), glm::vec2(1, 0)),//0
				VertexFormat(glm::vec3(-1, -1,  1), color, glm::vec3(-1, 0, 0), glm::vec2(1, 1)),//1
				VertexFormat(glm::vec3(-1, -1,  1), color, glm::vec3(0, -1, 0), glm::vec2(0, 0)),//2

				// 1
				VertexFormat(glm::vec3(1, -1,  1), color, glm::vec3(0, 0, 1), glm::vec2(1, 1)),//3
				VertexFormat(glm::vec3(1, -1,  1), color, glm::vec3(1, 0, 0), glm::vec2(1, 0)),//4
				VertexFormat(glm::vec3(1, -1,  1), color, glm::vec3(0, -1, 0), glm::vec2(0, 1)),//5

				// 2
				VertexFormat(glm::vec3(-1,  1,  1), color, glm::vec3(0, 0, 1), glm::vec2(0, 0)),//6
				VertexFormat(glm::vec3(-1,  1,  1), color, glm::vec3(-1, 0, 0), glm::vec2(0, 1)),//7
				VertexFormat(glm::vec3(-1,  1,  1), color, glm::vec3(0, 1, 0), glm::vec2(1, 0)),//8

				// 3
				VertexFormat(glm::vec3(1,  1,  1), color, glm::vec3(0, 0, 1), glm::vec2(0, 1)),//9
				VertexFormat(glm::vec3(1,  1,  1), color, glm::vec3(1, 0, 0), glm::vec2(0, 0)),//10
				VertexFormat(glm::vec3(1,  1,  1), color, glm::vec3(0, 1, 0), glm::vec2(1, 1)),//11

				// 4
				VertexFormat(glm::vec3(-1, -1, -1), color, glm::vec3(0, 0, -1), glm::vec2(1, 1)),//12
				VertexFormat(glm::vec3(-1, -1, -1), color, glm::vec3(-1, 0, 0), glm::vec2(1, 0)),//13
				VertexFormat(glm::vec3(-1, -1, -1), color, glm::vec3(0, -1, 0), glm::vec2(1, 0)),//14

				// 5
				VertexFormat(glm::vec3(1, -1, -1), color, glm::vec3(0, 0, -1), glm::vec2(1, 0)),//15
				VertexFormat(glm::vec3(1, -1, -1), color, glm::vec3(1, 0, 0), glm::vec2(1, 1)),//16
				VertexFormat(glm::vec3(1, -1, -1), color, glm::vec3(0, -1, 0), glm::vec2(1, 1)),//17

				// 6
				VertexFormat(glm::vec3(-1,  1, -1), color, glm::vec3(0, 0, -1), glm::vec2(0, 1)),//18
				VertexFormat(glm::vec3(-1,  1, -1), color, glm::vec3(-1, 0, 0), glm::vec2(0, 0)),//19
				VertexFormat(glm::vec3(-1,  1, -1), color, glm::vec3(0, 1, 0), glm::vec2(0, 0)),//20

				// 7
				VertexFormat(glm::vec3(1,  1, -1), color, glm::vec3(0, 0, -1), glm::vec2(0, 0)),//21
				VertexFormat(glm::vec3(1,  1, -1), color, glm::vec3(1, 0, 0), glm::vec2(0, 1)),//22
				VertexFormat(glm::vec3(1,  1, -1), color, glm::vec3(0, 1, 0), glm::vec2(0, 1)),//23
			};

			std::vector<unsigned short> indices =
			{
				0, 3, 6,		3, 9, 6,
				8, 11, 23,		8, 23, 20,
				4, 22, 10,		4, 16, 22,
				18, 21, 12,		21, 15, 12,
				2, 14, 5,		5, 14, 17,
				7, 19, 13,		1, 7, 13,
			};

		return CreateMesh(name, vertices, indices);
	}

	Mesh* CreatePyramid(std::string name, glm::vec3 color) {
		std::vector<VertexFormat> vertices{
			// 0
			VertexFormat(glm::vec3(-0.5f, 0,  1 - 0.5f), color, glm::vec3(0, 1, 1), glm::vec2(1, 0)),//0
			VertexFormat(glm::vec3(-0.5f, 0,  1 - 0.5f), color, glm::vec3(-1, 1, 0), glm::vec2(1, 1)),//1
			VertexFormat(glm::vec3(-0.5f, 0,  1 - 0.5f), color, glm::vec3(0, -1, 0), glm::vec2(0, 0)),//2

			// 1
			VertexFormat(glm::vec3(1 - 0.5f, 0,  1 - 0.5f), color, glm::vec3(0, 1, 1), glm::vec2(1, 1)),//3
			VertexFormat(glm::vec3(1 - 0.5f, 0,  1 - 0.5f), color, glm::vec3(1, 1, 0), glm::vec2(1, 0)),//4
			VertexFormat(glm::vec3(1 - 0.5f, 0,  1 - 0.5f), color, glm::vec3(0, -1, 0), glm::vec2(0, 1)),//5

			// 2
			VertexFormat(glm::vec3(1 - 0.5f, 0,  0 - 0.5f), color, glm::vec3(1, 1, 0), glm::vec2(1, 1)),//6
			VertexFormat(glm::vec3(1 - 0.5f, 0,  0 - 0.5f), color, glm::vec3(0, 1, -1), glm::vec2(1, 0)),//7
			VertexFormat(glm::vec3(1 - 0.5f, 0,  0 - 0.5f), color, glm::vec3(0, -1, 0), glm::vec2(1, 1)),//8

			// 3
			VertexFormat(glm::vec3(0 - 0.5f, 0,  0 - 0.5f), color, glm::vec3(0, 1, -1), glm::vec2(1, 1)),//9
			VertexFormat(glm::vec3(0 - 0.5f, 0,  0 - 0.5f), color, glm::vec3(-1, 1, 0), glm::vec2(1, 0)),//10
			VertexFormat(glm::vec3(0 - 0.5f, 0,  0 - 0.5f), color, glm::vec3(0, -1, 0), glm::vec2(1, 0)),//11

			// 4
			VertexFormat(glm::vec3(0.5f - 0.5f, 0.5f,  0.5f - 0.5f), color, glm::vec3(0, 1, 1), glm::vec2(0, 0.5f)),//12
			VertexFormat(glm::vec3(0.5f - 0.5f, 0.5f,  0.5f - 0.5f), color, glm::vec3(1, 1, 0), glm::vec2(0, 0.5f)),//13
			VertexFormat(glm::vec3(0.5f - 0.5f, 0.5f,  0.5f - 0.5f), color, glm::vec3(0, 1, -1), glm::vec2(0, 0.5f)),//14
			VertexFormat(glm::vec3(0.5f - 0.5f, 0.5f,  0.5f - 0.5f), color, glm::vec3(-1, 1, 0), glm::vec2(0, 0.5f)),//15
		};

		std::vector<unsigned short> indices = {
			0, 3, 12,// 0, 1, 4
			4, 6, 13,// 1, 2, 4
			7, 9, 14, // 2, 3, 4
			10, 1, 15,// 3, 0, 4
			2, 11, 8,// 0, 3, 2
			8, 5, 2,// 2, 1, 0
		};

		return CreateMesh(name, vertices, indices);
	}
}

