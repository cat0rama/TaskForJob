#include "Launcher.hpp"
#include "Window.hpp"
#include "Log.hpp"

#if defined(_WIN32) || defined(_WIN64)	//if window, we include <windows.h> its needed for FreeConsole() functions
#include <windows.h>
#endif

bool Launcher::Init() //initialize launcher
{
	XmlParser args;

	if (!args.Initialize("settings.xml", { "ShowConsole", "Title", "Heigth", "Weigth" })) {	 //xmlparser initialize with args from settings file
		return false;
	}

#if defined(_WIN32) || defined(_WIN64) //if OS windows we try to hide console with WinApi function FreeConsole()
	if (args.GetParameter("ShowConsole") == "false") {
		if (!FreeConsole()) {	//hide console func from winapi
			LOG_CRITICAL("Unable to hide console!");
		}
	}
#endif

	std::string title = args.GetParameter("Title"); //Get title form settings file

	pWindow = std::make_unique<Window>(title.c_str(),
		std::atoi(args.GetParameter("Heigth").c_str()), std::atoi(args.GetParameter("Weigth").c_str())); //initialize parameters from xml file

	if ((int)pWindow->InitWindow() <= 0) { //initialize window object
		return false; 
	}

	return true;
}

int Launcher::Start() //initialize launcher and start render loop
{
	if (!Init()) {	//initialize launcher
		getchar();	//if initialization returned a return error code, we wait for a character to display the error log
		return -1;	//return error code and exit from application
	}

	while (WindowOpen) {	//render while window is not close
		pWindow->OnUpdate();  //call render loop method
	}

	return 0;
}