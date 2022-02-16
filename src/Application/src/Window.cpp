#include "Window.hpp"
#include "Callback.hpp"
#include "Log.hpp"

Window::Window(const char* _title, const uint16_t _weigth, const uint16_t _heigth):
title(_title), width(_weigth), heigth(_heigth), pWindow(nullptr), Gui()
{	}

Window::Window(): title("TestWindow"), width(600), heigth(600), pWindow(nullptr), Gui()
{	}

Window::eWindowCode Window::InitWindow() noexcept //Create window, initialize gui library
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
	
	glfwSwapInterval(1);

	WindowOpen = true;
	return eWindowCode::SUCCES;
}

void Window::CallbacksInit() const noexcept
{
	glfwSetWindowCloseCallback(pWindow, callbacks::WindowCloseCallback);
	glfwSetWindowSizeCallback(pWindow, callbacks::WindowSizeCallback);
}

void Window::Shutdown() const noexcept //close window and terminate application
{
	glfwDestroyWindow(pWindow);
	glfwTerminate();
}

void Window::Widgets() const noexcept //overload widget method
{
	ImGui::Begin("UNIVER");

	if (ImGui::SliderFloat3("Change color", (float*)background, 0.0f, 1.0f, "color"))
	{
		LOG_INFO("Color slider changed! {0} {1} {2}", background[0], background[1], background[2]);
	}

	if (ImGui::Button("Test Button"))
	{
		LOG_INFO("Button clicked!");
	}

	std::vector<std::string> words = {"Univer", "Take", "Me", "To", "Job!"};
	static std::string current_item;

	if (ImGui::BeginCombo("##combo", current_item.c_str())) 
	{
		for (int i = 0; i < words.size(); i++) {
			bool is_selected = (current_item == words[i]);
			
			if (ImGui::Selectable(words[i].c_str(), is_selected)) {
				current_item = words[i];
			}
			
			if (is_selected) {
				ImGui::SetItemDefaultFocus();
				LOG_INFO("You take the element!");
			}
		}
		ImGui::EndCombo();
	}
}

void Window::OnUpdate() noexcept //window render function
{
	glClearColor(background[0], background[1], background[2], background[3]);
	glClear(GL_COLOR_BUFFER_BIT);

	GuiUpdate();

	glfwSwapBuffers(pWindow);
	glfwPollEvents();
}