#ifndef CALLBACK_HPP_
#define CALLBACK_HPP_

#include "Window.hpp"
#include "Log.hpp"

namespace callbacks
{
	void WindowSizeCallback(GLFWwindow* _pWindow, int _width, int _height);

	void WindowCloseCallback(GLFWwindow* _pWindow);
}

#endif // !CALLBACK_HPP_
