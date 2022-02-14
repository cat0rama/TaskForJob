#ifndef GUI_HPP_
#define GUI_HPP_

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

class Gui 
{
public:
	enum class eGuiCode
	{
		GUI_OPENGL_INIT_ERROR = -1, 
		GUI_GLFW_INIT_ERROR = -2, 
		SUCCES = 1
	};
public:
	Gui();

	virtual ~Gui();
public:
	virtual eGuiCode GuiInit(GLFWwindow* _pWindow) noexcept;

	virtual void PreRender() const noexcept;

	virtual void Widgets() const noexcept;

	virtual void GuiUpdate() noexcept;

	virtual void PostRender() const noexcept;

	virtual void Shutdown() const noexcept;
};

#endif // !GUI_HPP_
