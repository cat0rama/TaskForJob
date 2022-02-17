#include "Callback.hpp"

namespace callbacks
{
	void WindowSizeCallback(GLFWwindow* _pWindow, int _width, int _height)	//window resize callback
	{
		LOG_INFO("Window resized: {0} x {1}", _width, _height);
	}

	void WindowCloseCallback(GLFWwindow* _pWindow)	//window close callback
	{
		WindowOpen = false;
		LOG_WARN("Window closed!");
	}
}