//OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//GLM
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

//Systems
#include "./Systems/Window.h"
#include "./Systems/Events.h"
#include "./Systems/Camera.h"

//Graphics
#include "./Graphics/Mesh.h"
#include "./Graphics/Cube.h"
#include "./Graphics/Plane.h"
#include "./Graphics/Flashlight.h"
#include "./Graphics/Texture.h"
#include "./Graphics/Shader.h"

//Window params
int WIDTH = 800;
int HEIGHT = 600;

// Constanrs
float G = 9.8f * 1.6f;

float vertices[] = {
	// positions          // normals           // texture coords

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,

	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,

	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,

	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f

};

void solveCameraPhysics(Camera* camera, float& vSpeed, float deltaTime, bool& onGround);

int main()
{
	Window::init(WIDTH, HEIGHT, "Lighting");
	Events::init();

	Camera* camera = new Camera(glm::vec3(0.0f, 2.0f, 1.0f), 70);
	Texture* texture = new Texture("./Resources/wood_container.png", true);
	Texture* specTexture = new Texture("./Resources/wood_container_spec.png", true);
	Texture* emisTexture = new Texture("./Resources/wood_container_emis.png", true);
	Texture* groundTexture = new Texture("./Resources/deepslate_bricks.png");
	//Shader* shader = new Shader("./Shaders/vert.glsl", "./Shaders/frag.glsl");
	Shader* lampCubeShader = new Shader("./Shaders/lightVert.glsl", "./Shaders/lightFrag.glsl");
	Shader* multyLightsShader = new Shader("./Shaders/multiple_lights_vert.glsl", "./Shaders/multiple_lights_frag.glsl");

	Flashlight* flashlight = nullptr;  
	glm::mat4 objectMatrix(1.0f);
	glm::mat4 lightMatrix(1.0f);


	Mesh* ground = new Mesh(new Plane(-100, -100, 100, 100, -10)); 
	
	float camX = 0;
	float camY = 0;
	float sensetivity = 0.1f;

	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	float lastTime = glfwGetTime();
	float currentTime = 0;

	float udFPS = glfwGetTime();
	float vSpeed = 0.0f;
	bool onGround = true;

	while (!Window::shouldClose())
	{
		camera->fov = 70.0f;
		glm::vec3 up(0.0, 1.0, 0.0);
		float speed = 5;
		Window::clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		currentTime = glfwGetTime();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		if (currentTime - udFPS > 0.3)
		{
			int fps = int(1.0f / deltaTime);
			std::string title = "fps: ";
			title += std::to_string(fps);
			glfwSetWindowTitle(Window::window, title.c_str());
			udFPS = currentTime;
		}

		//Handling events
		if (Events::pressed(GLFW_KEY_Z))			camera->fov = 5.0f;
		if (Events::pressed(GLFW_KEY_LEFT_CONTROL))	{speed = 10; camera->fov = 75;}
		if (Events::pressed(GLFW_KEY_S))			camera->position += glm::cross(camera->right, up) * speed * deltaTime;
		if (Events::pressed(GLFW_KEY_W))			camera->position -= glm::cross(camera->right, up) * speed * deltaTime;
		if (Events::pressed(GLFW_KEY_A) && onGround)			camera->position -= camera->right * speed * deltaTime;
		if (Events::pressed(GLFW_KEY_D) && onGround)			camera->position += camera->right * speed * deltaTime;
		if (Events::pressed(GLFW_KEY_SPACE) && onGround) { vSpeed = 6; onGround = false; } //camera->position += up * speed * deltaTime;
		//if (Events::jpressed(GLFW_KEY_LEFT_SHIFT))  camera->position -= up * speed * deltaTime;
		if (Events::jpressed(GLFW_KEY_ESCAPE))		Window::setShouldClose(true);
		if (Events::jpressed(GLFW_KEY_TAB))			Events::toogleCursor();
		if (Events::cursor_locked)
		{
			camX += -Events::deltaX * sensetivity;
			camY += -Events::deltaY * sensetivity;

			if (camY > 89.0f)
				camY = 89.0f;
			if (camY < -89.0f)
				camY = -89.0f;

			camera->rotation = glm::mat4(1.0f);
			camera->rotate(glm::radians(camY), glm::radians(camX), 0);
		}
		if (Events::pressed(GLFW_KEY_X))
		{
			lightMatrix = glm::mat4(1.0f);
			objectMatrix = glm::rotate(objectMatrix, (float)deltaTime * speed / 3, glm::vec3(1.0f, 0.0f, 0.0f));
			objectMatrix = glm::rotate(objectMatrix, (float)deltaTime * speed / 3, glm::vec3(0.0f, 1.0f, 0.0f));
			objectMatrix = glm::rotate(objectMatrix, (float)deltaTime * speed / 3, glm::vec3(0.0f, 0.0f, 1.0f));
			//lit.position = glm::vec3(lightMatrix * glm::vec4(0, 0, 0, 1));
		}
		solveCameraPhysics(camera, vSpeed, deltaTime, onGround);
		
		//Draw stuff here
		glActiveTexture(GL_TEXTURE0);
		groundTexture->bind();
		glActiveTexture(GL_TEXTURE1);
		groundTexture->bind();

		if(flashlight == nullptr)
			flashlight = new Flashlight(0.09f, 0.032f, 12.5f, glm::vec3(0.1f), glm::vec3(0.8f), glm::vec3(1.0f), &camera->position, &camera->front);


		glm::mat4 model(1.0f);
		multyLightsShader->use();
		multyLightsShader->setFloat("material.shininess", 64);
		multyLightsShader->setInt("material.diffuse", 0);
		multyLightsShader->setInt("material.specular", 1);
		multyLightsShader->setMat4("projection", glm::value_ptr(camera->getProjection()));
		multyLightsShader->setMat4("view", glm::value_ptr(camera->getView()));
		multyLightsShader->setMat4("model", glm::value_ptr(model));
		//multyLightsShader->setLight(flashlight);³

		multyLightsShader->setVec3("spotLight.position", glm::value_ptr(camera->position));
		multyLightsShader->setVec3("spotLight.direction", glm::value_ptr(camera->front));
		multyLightsShader->setVec3("spotLight.ambient", glm::value_ptr(glm::vec3(0.0f, 0.0f, 0.0f)));
		multyLightsShader->setVec3("spotLight.diffuse", glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));
		//multyLightsShader->setVec3("spotLight.specular", glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));
		multyLightsShader->setFloat("spotLight.constant", 1.0f);
		multyLightsShader->setFloat("spotLight.linear", 0.0009f);
		multyLightsShader->setFloat("spotLight.quadratic", 0.000032f);
		multyLightsShader->setFloat("spotLight.cutOff", glm::cos(glm::radians(27.5f)));
		multyLightsShader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(35.0f)));
		ground->draw(GL_TRIANGLES);

		Window::swapBuffers();
		Events::pollEvents();
	}

	delete multyLightsShader;
	delete texture;
	delete camera;

	Window::final();
	return 0;
}

void solveCameraPhysics(Camera* camera, float& vSpeed, float deltaTime, bool& onGround)
{
	if (onGround) return;
	
	camera->position.y += vSpeed * deltaTime;
	vSpeed -= G * deltaTime;

	if (camera->position.y <= 20.0f)
	{
		onGround = true;
		camera->position.y = 20.0f;
		vSpeed = 0;
	}
}
