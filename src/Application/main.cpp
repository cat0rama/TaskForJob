#include "Launcher.hpp"
#include "Window.hpp"

int main(int argc, char* argv[])
{
	const Launcher app;

	return app.Start("TAKE TO WORK!", 600, 500);
}