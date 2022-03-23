#include "Window.h"

GLFWwindow* Window::window;
int Window::width;
int Window::height;

void Window::init(int width, int height, const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	Window::width = width;
	Window::height = height;

	if (window == nullptr)
	{
		std::cout << "Failed to open the window." << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize glad." << std::endl;
		exit(-1);
	}
	glViewport(0, 0, width, height);
}

void Window::final()
{
	glfwTerminate();
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::setShouldClose(bool flag)
{
	glfwSetWindowShouldClose(window, flag);
}

void Window::setClearColor(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
}

void Window::clear(int bufferToClear)
{
	glClear(bufferToClear);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(window);
}

void Window::setCursorMode(int mode)
{
	glfwSetInputMode(window, GLFW_CURSOR, mode);
}
