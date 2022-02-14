#ifndef GUI_HPP_
#define GUI_HPP_

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

class Gui 
{
public:
	Gui();

	virtual ~Gui();
public:
	void Shutdown() const noexcept;

	void PreRender() const noexcept;

	void PostRender() const noexcept;
protected:

};

#endif // !GUI_HPP_
