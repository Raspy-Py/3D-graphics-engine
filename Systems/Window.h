#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class GLFWwindow;
class Window
{
public:
	static int width;
	static int height;
	static GLFWwindow* window;

	static void init(int width, int height, const char* title);
	static void final();
	static bool shouldClose();
	static void setShouldClose(bool flag);
	static void setClearColor(float r, float g, float b);
	static void clear(int bufferToClear);
	static void swapBuffers();
	static void setCursorMode(int mode);
private:
};
