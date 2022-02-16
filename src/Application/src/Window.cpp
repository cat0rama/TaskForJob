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

	if (!glfwInit()) {	//glfw lib initialize
		LOG_CRITICAL("GLFW INITIALIZE ERROR!");
		return eWindowCode::GLFW_INIT_ERROR;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);		//glfw version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if(!(pWindow = glfwCreateWindow(width, heigth, title, NULL, NULL))) {	//glfw create window with args
		LOG_CRITICAL("GFLW WINDOW INITIALIZE ERROR!");
		return eWindowCode::GLFW_WINDOW_INIT_ERROR;
	}

	glfwMakeContextCurrent(pWindow);	//set current window context

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {	//openGL load functions
		LOG_CRITICAL("GLAD INITIALIZE ERROR!");
		return eWindowCode::GLAD_INIT_ERROR;
	}

	CallbacksInit();	//initialize window callbacks

	if ((int)GuiInit(pWindow) <= 0) {	//initialize Gui class
		LOG_CRITICAL("GUI INIT ERROR!");
		return eWindowCode::GUI_INIT_ERROR;
	}
	
	glfwSwapInterval(1);	//setting the processing of the number of frames according to the screen frequency

	WindowOpen = true;	//if all initialization succes, the window is considered open
	return eWindowCode::SUCCES;
}

void Window::CallbacksInit() const noexcept	//set glfw callbacks functions
{
	glfwSetWindowCloseCallback(pWindow, callbacks::WindowCloseCallback);
	glfwSetWindowSizeCallback(pWindow, callbacks::WindowSizeCallback);
}

void Window::Shutdown() const noexcept //close window and terminate application
{
	glfwDestroyWindow(pWindow);
	glfwTerminate();
}

void Window::Widgets() const noexcept //overload widget method with custom widgets
{
	ImGui::Begin("UNIVER");		//test window name

	if (ImGui::SliderFloat3("Change color", (float*)background, 0.0f, 1.0f, "color"))	//test slider
	{
		LOG_INFO("Color slider changed! {0} {1} {2}", background[0], background[1], background[2]);
	}

	if (ImGui::Button("Test Button"))	//test button
	{
		LOG_INFO("Button clicked!");
	}

	static std::vector<std::string> words = {"Univer", "Take", "Me", "To", "Job!"};
	static std::string current_item;

	if (ImGui::BeginCombo("##combo", current_item.c_str())) //select with some options
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

void Window::OnUpdate() noexcept //window render method
{
	glClearColor(background[0], background[1], background[2], background[3]); //render background with RGBA
	glClear(GL_COLOR_BUFFER_BIT);	//clear buffers

	GuiUpdate();	//gui render

	glfwSwapBuffers(pWindow);  //vertical retrace synchronization
	glfwPollEvents();	//click handler
}