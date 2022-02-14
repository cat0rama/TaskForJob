#include "Launcher.hpp"
#include "Window.hpp"

int main(int argc, char* argv[])
{
	const Launcher app;

	return app.Start("TestWindow", 800, 800);
}