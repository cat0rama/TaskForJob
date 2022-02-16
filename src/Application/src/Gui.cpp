#include "Gui.hpp"
#include "Log.hpp"

Gui::Gui()	//ImGui checkversion
{
	IMGUI_CHECKVERSION();
}

Gui::~Gui()
{
	Shutdown();
}

Gui::eGuiCode Gui::GuiInit(GLFWwindow* _pWindow) noexcept	//ImGui lib init
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	if (!ImGui_ImplOpenGL3_Init("#version 300 es")) {
		LOG_CRITICAL("IMGUI OPENGL INIT ERROR!");
		return eGuiCode::GUI_OPENGL_INIT_ERROR;
	}

	if (!ImGui_ImplGlfw_InitForOpenGL(_pWindow, true)) {
		LOG_CRITICAL("IMGUI GLFW INIT ERROR!");
		return eGuiCode::GUI_GLFW_INIT_ERROR;
	}
	
	return eGuiCode::SUCCES;
}

void Gui::PreRender() const noexcept  //ImGui pre render function
{
	ImGui_ImplOpenGL3_NewFrame();      
	ImGui_ImplGlfw_NewFrame();          
	ImGui::NewFrame();
}

void Gui::Widgets() const noexcept  //Basic widgets if method not overload
{
	ImGui::Begin("TestWindow");
}

void Gui::GuiUpdate() noexcept	//gui render loop
{
	PreRender();

	Widgets();

	PostRender();
}

void Gui::PostRender() const noexcept //ImGui post render function
{
	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Gui::Shutdown() const noexcept	  //terminate Gui and Imgui context
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}