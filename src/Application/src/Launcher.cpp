#include "Launcher.hpp"
#include "Window.hpp"

bool Launcher::Init() 
{
	XmlParser args;

	if (!args.Initialize("settings.xml", { "ShowConsole", "Title", "Heigth", "Weigth" })) {
		return false;
	}

	std::string title = args.GetParameter("Title"); //Получаем имя окна из файла settings.xml для примера

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
		return -1;
	}

	while (WindowOpen) {
		pWindow->OnUpdate();
	}

	return 0;
}