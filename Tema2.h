#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>

#include "../Tema2/Utils/Position/Position3D.h"
#include "Utils/Platform/Platform.h"
#include "Utils/Player/Player.h"
#include "Defines.h"

class Tema2 : public SimpleScene {
public:
	Tema2();
	~Tema2();
	void Init() override;


private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix);
	Mesh* CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);
	void createPlayerMesh();
	void createGreenPlatformMesh();
	void createRedPlatformMesh();
	void createYellowPlatformMesh();
	void createOrangePlatformMesh();
	void setCameraFirstPerson();
	void setCameraThirdPerson();

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

protected:
	glm::mat3 modelMatrix;
	//Position3D pos = Position3D(0, SPHERE_DEFAULT_HEIGHT, 0);

	bool cameraIsThirdPerson = true;
	Player player = Player();
	Platform platforms[MAX_PLATFORM_NUMBER];
	int lastPlatformOnColumn[MAX_PLATFORM_COLUMNS] = { 0 };
};