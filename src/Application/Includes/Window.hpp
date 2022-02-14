#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Log.hpp"

inline bool WindowOpen = false;

class Window
{
public:
	enum class eWindowCode
	{
		OPENGL_INIT_ERROR = -1, IMGUI_INIT_ERROR = -2,
		GLAD_INIT_ERROR = -3, GLFW_INIT_ERROR = -4,
		GLFW_WINDOW_INIT_ERROR = -5, INIT_SUCCES = 1
	};
public:
	explicit Window(const char* _title, const uint16_t _weigth, const uint16_t _heigth);

	Window();

	~Window() { Shutdown(); };
public:
	Window(const Window&) = delete;
	Window(Window&&) = delete;

	Window& operator=(const Window&) = delete;
	Window& operator=(Window&&) = delete;
public:
	eWindowCode InitWindow() noexcept;

	void Shutdown() const noexcept;

	void CallbacksInit() const noexcept;

	void OnUpdate() noexcept;
private:
	GLfloat background[4] = { 0.f };
	GLFWwindow* pWindow;
private:
	uint16_t width, heigth;
	const char* title;
};

#endif // !WINDOW_HPP_
