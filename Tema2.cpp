#include "Tema2.h"

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <Core/Engine.h>
#include "Transformations/Object2D.h"
#include "Transformations/UtilDef.h"
#include "Transformations/Transform3D.h"
#include "Transformations/Transform2D.h"
#include "Defines.h"


using namespace std;

const char *platform_mesh_name[5] = { BLUE_PLATFORM_NAME, GREEN_PLATFORM_NAME,  YELLOW_PLATFORM_NAME, ORANGE_PLATFORM_NAME, RED_PLATFORM_NAME };

Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

void Tema2::createPlayerMesh()
{
	{
		Mesh* mesh = new Mesh("player");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}
}
void Tema2::createRedPlatformMesh()
{
	// Create a simple cube
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.2)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0, 0), glm::vec3(0.9, 0.4, 0.2)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0, 0), glm::vec3(0.7, 0.7, 0.1)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(1, 0, 0), glm::vec3(0.7, 0.3, 0.7)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 0, 0), glm::vec3(0.3, 0.5, 0.4)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(1, 0, 0), glm::vec3(0.5, 0.2, 0.9)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 0, 0), glm::vec3(0.7, 0.0, 0.7)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(1, 0, 0), glm::vec3(0.1, 0.5, 0.8)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh(RED_PLATFORM_NAME, vertices, indices);
	}
}
void Tema2::createYellowPlatformMesh()
{
	// Create a simple cube
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(1, 1, 0), glm::vec3(0.2, 0.8, 0.2)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 1, 0), glm::vec3(0.9, 0.4, 0.2)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 1, 0), glm::vec3(0.7, 0.7, 0.1)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(1, 1, 0), glm::vec3(0.7, 0.3, 0.7)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 0), glm::vec3(0.3, 0.5, 0.4)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(1, 1, 0), glm::vec3(0.5, 0.2, 0.9)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 1, 0), glm::vec3(0.7, 0.0, 0.7)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(1, 1, 0), glm::vec3(0.1, 0.5, 0.8)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh(YELLOW_PLATFORM_NAME, vertices, indices);
	}
}
void Tema2::createOrangePlatformMesh()
{
	// Create a simple cube
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(1, 0.4f, 0), glm::vec3(0.2, 0.8, 0.2)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0.4f, 0), glm::vec3(0.9, 0.4, 0.2)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0.4f, 0), glm::vec3(0.7, 0.7, 0.1)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(1, 0.4f, 0), glm::vec3(0.7, 0.3, 0.7)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 0.4f, 0), glm::vec3(0.3, 0.5, 0.4)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(1, 0.4f, 0), glm::vec3(0.5, 0.2, 0.9)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 0.4f, 0), glm::vec3(0.7, 0.0, 0.7)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(1, 0.4f, 0), glm::vec3(0.1, 0.5, 0.8)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh(ORANGE_PLATFORM_NAME, vertices, indices);
	}
}
void Tema2::createGreenPlatformMesh()
{
	// Create a simple cube
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 1, 0), glm::vec3(0.2, 0.8, 0.2)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(0, 1, 0), glm::vec3(0.9, 0.4, 0.2)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(0, 1, 0), glm::vec3(0.7, 0.7, 0.1)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(0, 1, 0), glm::vec3(0.7, 0.3, 0.7)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(0, 1, 0), glm::vec3(0.3, 0.5, 0.4)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 1, 0), glm::vec3(0.5, 0.2, 0.9)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(0, 1, 0), glm::vec3(0.7, 0.0, 0.7)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(0, 1, 0), glm::vec3(0.1, 0.5, 0.8)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh(GREEN_PLATFORM_NAME, vertices, indices);
	}
}
void Tema2::createPurplePlatformMesh()
{
	// Create a simple cube
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(1, 0, 0.5f), glm::vec3(0.2, 0.8, 0.2)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0, 0.5f), glm::vec3(0.9, 0.4, 0.2)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0, 0.5f), glm::vec3(0.7, 0.7, 0.1)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(1, 0, 0.5f), glm::vec3(0.7, 0.3, 0.7)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 0, 0.5f), glm::vec3(0.3, 0.5, 0.4)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(1, 0, 0.5f), glm::vec3(0.5, 0.2, 0.9)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 0, 0.5f), glm::vec3(0.7, 0.0, 0.7)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(1, 0, 0.5f), glm::vec3(0.1, 0.5, 0.8)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh(PURPLE_PLATFORM_NAME, vertices, indices);
	}
}
void Tema2::createBluePlatformMesh()
{
	// Create a simple cube
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 0, 1), glm::vec3(0.2, 0.8, 0.2)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(0, 0, 1), glm::vec3(0.9, 0.4, 0.2)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(0, 0, 1), glm::vec3(0.7, 0.7, 0.1)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(0, 0, 1), glm::vec3(0.7, 0.3, 0.7)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(0, 0, 1), glm::vec3(0.3, 0.5, 0.4)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 0, 1), glm::vec3(0.5, 0.2, 0.9)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(0, 0, 1), glm::vec3(0.7, 0.0, 0.7)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(0, 0, 1), glm::vec3(0.1, 0.5, 0.8)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh(BLUE_PLATFORM_NAME, vertices, indices);
	}
}

void Tema2::Init()
{
	// set camera and world
	{
		camera = new MyCamera();
		camera->Set(glm::vec3(CAMERA_X_THIRD, CAMERA_Y_THIRD, CAMERA_Z_THIRD), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
	}



	// init meshes
	createPlayerMesh();
	createRedPlatformMesh();
	createYellowPlatformMesh();
	createOrangePlatformMesh();
	createGreenPlatformMesh();
	createBluePlatformMesh();
	createPurplePlatformMesh();
	// FUEL level
	{
		glm::vec3 center = glm::vec3(0, 0, 0);
		Mesh* fuelBar = Object2D::CreateRectangle("fuelBar", center, 1, 1, glm::vec3(0.1f, 1, 0.1f), true);
		AddMeshToList(fuelBar);
	}


	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader* shader = new Shader("PatrickShader");
		shader->AddShader("Source/Laboratoare/Tema2/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Tema2/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}


	srand((unsigned int)time(NULL));

	
	// render platforms
	{
		int lastColumnPos[MAX_PLATFORM_COLUMNS] = {0};
		int half = MAX_PLATFORM_COLUMNS / 2;
		int offset = half * (PLATFORM_WIDTH + GAP_BETWEEN_PLATFORMS_SIZE);

		for (int i = 0; i < MAX_PLATFORM_NUMBER; i++) {
			platforms[i].id = i;
			platforms[i].column = i % MAX_PLATFORM_COLUMNS;
			platforms[i].lenght = rand() % (PLATFORM_MAX_LENGTH - PLATFORM_LENGTH + 1) + PLATFORM_LENGTH;


			platforms[i].pos.z = (-1) * (lastColumnPos[platforms[i].column] + platforms[i].lenght / 2);
			platforms[i].pos.y = (-1) * (PLATFORM_HEIGHT);
			platforms[i].pos.x = offset -  (platforms[i].column * (PLATFORM_WIDTH + GAP_BETWEEN_PLATFORMS_SIZE));
			platforms[i].isOutOfScreen = false;
			platforms[i].isTouched = false;
			platforms[i].type = rand() % 5;

			// don t want to create red platform too often
			if (platforms[i].type == RED_PLATFORM) {
				if (!player.LastRedCountIsOver()) {
					platforms[i].type = rand() % 4;
				}
				else {
					player.startLastRedCount();
				}
			}
			 
			lastColumnPos[platforms[i].column] += platforms[i].lenght + GAP_BETWEEN_PLATFORMS_SIZE;   // update the next available z
			lastPlatformOnColumn[platforms[i].column] = i;   // set it as the last platform in this column
		}
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


void Tema2::Update(float deltaTimeSeconds)
{
	// FUEL level
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::MyTranslate(FUEL_BAR_X, FUEL_BAR_Y, FUEL_BAR_Z);
		modelMatrix *= Transform3D::MyScale(player.fuel / FUEL_BAR_SCALE_X, 0.1f / FUEL_BAR_SCALE_Y, 0);
		modelMatrix *= Transform3D::MyTranslate(HALF_RECTANGLE_LENGTH, 0, 0);
		Render2DMesh(meshes[GREEN_PLATFORM_NAME], shaders["VertexColor"], modelMatrix);
	}


	// MOVE FIRST PERSON CAMERA
	{
		if (!cameraIsThirdPerson) setCameraFirstPerson();
	}

	{
		// MUST CHECK FOR PLAYER COMMANDS FIRST
		// check for jumping, and speed penalty
		player.ajustPlayerHeight();
	}


	// RENDER PLATFORMS
	{
		for (int i = 0; i < MAX_PLATFORM_NUMBER; i++) {
			// move and generate platform
			int column = platforms[i].column;
			Platform lastPlatform = platforms[lastPlatformOnColumn[column]];
			int lastPlatformId = platforms[i].updatePlatform(lastPlatform, player);
			lastPlatformOnColumn[column] = lastPlatformId;

			// check for collision and apply effects
			platforms[i].checkForCollision(player);

			// draw them
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::MyTranslate(platforms[i].pos.x, platforms[i].pos.y, platforms[i].pos.z);
			modelMatrix *= Transform3D::MyScale(PLATFORM_WIDTH / 2, PLATFORM_HEIGHT, platforms[i].lenght / 2);

			if (platforms[i].isTouched) RenderSimpleMesh(meshes[PURPLE_PLATFORM_NAME], shaders["VertexColor"], modelMatrix);
			else RenderSimpleMesh(meshes[platform_mesh_name[platforms[i].type]], shaders["VertexColor"], modelMatrix);
		}
	}
	
	// RENDER PLAYER
	{
		// check to see if player fell
		int platformLength = -1;
		Position3D platPos = Position3D();
		if (player.touchingPlatformID != -1) {
			platformLength = platforms[player.touchingPlatformID].lenght;
			platPos = platforms[player.touchingPlatformID].pos;
		}
		bool hasFallen = player.checkForFalling(platformLength, platPos);
		if (player.gameOver) {
			glClearColor(0.5f, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			player.startGameOverAnimation();
			if (player.gameOverAnimationFinished()) {
				cout << "GAME OVER !" << endl;
				exit(0);
			}
		}



		if (cameraIsThirdPerson)
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::MyTranslate(player.pos.x, player.pos.y, player.pos.z);
			if (player.endNoiseAnimation()) RenderSimpleMesh(meshes["player"], shaders["PatrickShader"], modelMatrix);
			else RenderDistortedMesh(meshes["player"], shaders["PatrickShader"], modelMatrix);
		}
	}
}

void Tema2::setCameraFirstPerson()
{
	camera->position = glm::vec3(player.pos.x + CAMERA_X_THIRD, player.pos.y + CAMERA_Y_THIRD - 1, CAMERA_Z_THIRD - 5);
}
void Tema2::setCameraThirdPerson()
{
	camera->Set(glm::vec3(CAMERA_X_THIRD, CAMERA_Y_THIRD, CAMERA_Z_THIRD), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
}


Mesh* Tema2::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
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

	// TODO: Crete the IBO and bind it
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
	meshes[name] = new Mesh(name);
	meshes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	meshes[name]->vertices = vertices;
	meshes[name]->indices = indices;
	return meshes[name];
}

void Tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);


	int location = glGetUniformLocation(shader->program, "v_color");
	glUniform3f(location, 0.5f, 1, 0.5f);

	// TODO : get shader location for uniform mat4 "Model"
	GLint modelLocation = glGetUniformLocation(shader->GetProgramID(), "Model");


	// TODO : set shader uniform "Model" to modelMatrix
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// TODO : get shader location for uniform mat4 "View"
	GLint viewLocation = glGetUniformLocation(shader->GetProgramID(), "View");

	// TODO : set shader uniform "View" to viewMatrix
	glm::mat4 viewMatrix = camera->GetViewMatrix();
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// TODO : get shader location for uniform mat4 "Projection"
	GLint projLocation = glGetUniformLocation(shader->GetProgramID(), "Projection");

	// TODO : set shader uniform "Projection" to projectionMatrix
	glm::mat4 projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// get + set  time
	GLint timeLocation = glGetUniformLocation(shader->GetProgramID(), "time");
	glUniform1f(timeLocation, 0);	// get + set  time

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

void Tema2::RenderDistortedMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// TODO : get shader location for uniform mat4 "Model"
	GLint modelLocation = glGetUniformLocation(shader->GetProgramID(), "Model");


	// TODO : set shader uniform "Model" to modelMatrix
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// TODO : get shader location for uniform mat4 "View"
	GLint viewLocation = glGetUniformLocation(shader->GetProgramID(), "View");

	// TODO : set shader uniform "View" to viewMatrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// TODO : get shader location for uniform mat4 "Projection"
	GLint projLocation = glGetUniformLocation(shader->GetProgramID(), "Projection");

	// TODO : set shader uniform "Projection" to projectionMatrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// get + set  time

	GLint timeLocation = glGetUniformLocation(shader->GetProgramID(), "time");
	glUniform1f(timeLocation, (GLfloat)Engine::GetElapsedTime());	// get + set  time

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

void Tema2::Render2DMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// TODO : get shader location for uniform mat4 "Model"
	GLint modelLocation = glGetUniformLocation(shader->GetProgramID(), "Model");


	// TODO : set shader uniform "Model" to modelMatrix
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));



	// TODO : get shader location for uniform mat4 "View"
	GLint viewLocation = glGetUniformLocation(shader->GetProgramID(), "View");

	// TODO : set shader uniform "View" to viewMatrix
	//glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	glm::mat4 viewMatrix = glm::mat4(1);
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// TODO : get shader location for uniform mat4 "Projection"
	GLint projLocation = glGetUniformLocation(shader->GetProgramID(), "Projection");

	// TODO : set shader uniform "Projection" to projectionMatrix
	glm::mat4 projectionMatrix = glm::mat4(1);
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// get + set  time
	GLint timeLocation = glGetUniformLocation(shader->GetProgramID(), "time");
	glUniform1f(timeLocation, 0);	// get + set  time

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}



void Tema2::FrameEnd()
{
	//DrawTemaCoordinat();
}

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_A) && !player.gameOver)
	{
		player.pos.x = glm::max(PLAYER_MAX_LEFT, player.pos.x - PLAYER_X_MOVE_STEP);
	}

	if (window->KeyHold(GLFW_KEY_D) && !player.gameOver)
	{
		player.pos.x = glm::min(PLAYER_MAX_RIGHT, player.pos.x + PLAYER_X_MOVE_STEP);
	}

	if (window->KeyHold(GLFW_KEY_W) && !player.gameOver)
	{
		player.increaseSpeed();
	}

	if (window->KeyHold(GLFW_KEY_S) && !player.gameOver)
	{
		player.decreaseSpeed();
	}

	if (window->KeyHold(GLFW_KEY_SPACE) && player.y_axe_movement_type == PLAYER_ON_THE_GROUND && !player.gameOver) {
		player.y_axe_movement_type = PLAYER_IS_TAKING_OFF;
	}
}

void Tema2::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_C && !player.gameOver)
	{
		cameraIsThirdPerson = cameraIsThirdPerson ^ true ^ false;
		if (cameraIsThirdPerson) setCameraThirdPerson();
		else setCameraFirstPerson();
		cout << (cameraIsThirdPerson ? "third" : "first") << endl;
	}
}

void Tema2::OnKeyRelease(int key, int mods)
{
	// add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{

}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{

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
