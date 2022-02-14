#include "Launcher.hpp"

int Launcher::Start(const char* _title, const uint16_t _weigth, const uint16_t _heigth)
{
	Window pWindow(_title, _weigth, _heigth);

	if ((int)pWindow.InitWindow() <= 0) { return -1; }

	while (WindowOpen) {
		pWindow.OnUpdate();
	}

	return 0;
}