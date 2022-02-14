#include "Window.hpp"
#include "Callback.hpp"

Window::Window(const char* _title, const uint16_t _weigth, const uint16_t _heigth):
title(_title), width(_weigth), heigth(_heigth), pWindow(nullptr), Gui()
{	}

Window::Window(): title("TestWindow"), width(600), heigth(600), pWindow(nullptr), Gui()
{	}

Window::eWindowCode Window::InitWindow() noexcept
{	
	LOG_DEBUG("Initialize window with: {0} x {1}", width, heigth);

	if (!glfwInit()) {
		LOG_CRITICAL("GLFW INITIALIZE ERROR!");
		return eWindowCode::GLFW_INIT_ERROR;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if(!(pWindow = glfwCreateWindow(width, heigth, title, NULL, NULL))) {
		LOG_CRITICAL("GFLW WINDOW INITIALIZE ERROR!");
		return eWindowCode::GLFW_WINDOW_INIT_ERROR;
	}

	glfwMakeContextCurrent(pWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG_CRITICAL("GLAD INITIALIZE ERROR!");
		return eWindowCode::GLAD_INIT_ERROR;
	}

	CallbacksInit();

	if ((int)GuiInit(pWindow) <= 0) {
		LOG_CRITICAL("GUI INIT ERROR!");
		return eWindowCode::GUI_INIT_ERROR;
	}
	
	WindowOpen = true;
	return eWindowCode::SUCCES;
}

void Window::CallbacksInit() const noexcept
{
	glfwSetWindowCloseCallback(pWindow, callbacks::WindowCloseCallback);
	glfwSetWindowSizeCallback(pWindow, callbacks::WindowSizeCallback);
}

void Window::Shutdown() const noexcept
{
	glfwDestroyWindow(pWindow);
	glfwTerminate();
}

void Window::Widgets() const noexcept //переопределили базовый метод виджетов чтобы задавать свои
{
	ImGui::Begin("UNIVER");

	if (ImGui::SliderFloat3("Change Background color", (float*)background, 0.0f, 1.0f, "color"))
	{
		LOG_INFO("Slider changed!");
	}

	if (ImGui::Button("Test Button"))
	{
		LOG_INFO("Button clicked!");
	}
}

void Window::OnUpdate() noexcept
{
	glClearColor(background[0], background[1], background[2], background[3]);
	glClear(GL_COLOR_BUFFER_BIT);

	GuiUpdate();

	glfwSwapBuffers(pWindow);
	glfwPollEvents();
}