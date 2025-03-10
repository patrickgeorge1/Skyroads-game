#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Object2D
{

	// Create square with given bottom left corner, length and color
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill);
	Mesh* CreateRectangle(std::string name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill);
	Mesh* CreatePlayer(std::string name, glm::vec3 leftBottomCorner, float height, glm::vec3 color, bool fill);
	Mesh* CreateArrow(std::string name, glm::vec3 leftBottomCorner, float lenght, glm::vec3 color, bool fill);
	Mesh* CreateBalloon(std::string name, glm::vec3 leftBottomCorner, float minRadius, glm::vec3 color, bool fill);
	Mesh* CreateShuriken(std::string name, glm::vec3 leftBottomCorner, float radius, glm::vec3 color, bool fill);
}

