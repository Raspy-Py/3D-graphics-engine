#pragma once
#include "Window.h"

using uint = unsigned int;

class Events {
public:
	static bool* keys;
	static uint* frames;
	static uint current;
	static float deltaX;
	static float deltaY;
	static float x;
	static float y;
	static bool cursor_locked;
	static bool cursor_started;

	static int init();
	static void pollEvents();

	static bool pressed(int keycode);
	static bool jpressed(int keycode);

	static bool clicked(int button);
	static bool jclicked(int button);

	static void toogleCursor();
};