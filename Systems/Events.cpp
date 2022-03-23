#include "Events.h"
#include <GLFW/glfw3.h>
#include <string.h>

bool* Events::keys;
uint* Events::frames;
uint Events::current = 0;
float Events::deltaX = 0.0f;
float Events::deltaY = 0.0f;
float Events::x = 0.0f;
float Events::y = 0.0f;
bool Events::cursor_locked = false;
bool Events::cursor_started = false;

#define _MOUSE_BUTTONS 1024

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	if (Events::cursor_started) {
		Events::deltaX += xpos - Events::x;
		Events::deltaY += ypos - Events::y;
	}
	else {
		Events::cursor_started = true;
	}
	Events::x = xpos;
	Events::y = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) {
		Events::keys[_MOUSE_BUTTONS + button] = true;
		Events::frames[_MOUSE_BUTTONS + button] = Events::current;
	}
	else if (action == GLFW_RELEASE) {
		Events::keys[_MOUSE_BUTTONS + button] = false;
		Events::frames[_MOUSE_BUTTONS + button] = Events::current;
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action == GLFW_PRESS) {
		Events::keys[key] = true;
		Events::frames[key] = Events::current;
	}
	else if (action == GLFW_RELEASE) {
		Events::keys[key] = false;
		Events::frames[key] = Events::current;
	}
}

void window_size_callback(GLFWwindow* window, int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight);

	Window::width = newWidth;
	Window::height = newHeight;
}

int Events::init() {
	GLFWwindow* window = Window::window;
	keys = new bool[1032];
	frames = new uint[1032];

	memset(keys, false, 1032 * sizeof(bool));
	memset(frames, 0, 1032 * sizeof(uint));

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
	return 0;
}

bool Events::pressed(int keycode) {
	if (keycode < 0 || keycode >= _MOUSE_BUTTONS)
		return false;
	return keys[keycode];
}

bool Events::jpressed(int keycode) {
	if (keycode < 0 || keycode >= _MOUSE_BUTTONS)
		return false;
	return keys[keycode] && frames[keycode] == current;
}

bool Events::clicked(int button) {
	int index = _MOUSE_BUTTONS + button;
	return keys[index];
}

bool Events::jclicked(int button) {
	int index = _MOUSE_BUTTONS + button;
	return keys[index] && frames[index] == current;
}

void Events::toogleCursor()
{
	cursor_locked = !cursor_locked;

	Window::setCursorMode(cursor_locked ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void Events::pollEvents() {
	current++;
	deltaX = 0.0f;
	deltaY = 0.0f;
	glfwPollEvents();
}