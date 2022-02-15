#include "Launcher.hpp"
#include "Window.hpp"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

bool Launcher::Init() 
{
	XmlParser args;

	if (!args.Initialize("settings.xml", { "ShowConsole", "Title", "Heigth", "Weigth" })) {
		return false;
	}

#if defined(_WIN32) || defined(_WIN64) //if OS windows we try to hide console with WinApi function FreeConsole()
	if (args.GetParameter("ShowConsole") == "true") {
		if (!FreeConsole()) {
			LOG_CRITICAL("Unable to hide console!");
		}
	}
#endif

	std::string title = args.GetParameter("Title"); //Get title form settings file

	pWindow = std::make_unique<Window>(title.c_str(),
		std::atoi(args.GetParameter("Heigth").c_str()), std::atoi(args.GetParameter("Weigth").c_str()));

	if ((int)pWindow->InitWindow() <= 0) { 
		return false; 
	}

	return true;
}

int Launcher::Start()
{
	if (!Init()) {
		getchar();
		return -1;
	}

	while (WindowOpen) {
		pWindow->OnUpdate();
	}

	return 0;
}