#include "Callback.hpp"

namespace callbacks
{
	void WindowSizeCallback(GLFWwindow* _pWindow, int _width, int _height)
	{
		LOG_INFO("Window resized: {0} x {1}", _width, _height);
	}

	void WindowCloseCallback(GLFWwindow* _pWindow)
	{
		WindowOpen = false;
		LOG_WARN("Window closed!");
	}
}