#include "Launcher.hpp"

int Launcher::Start(const char* _title, const uint16_t _weigth, const uint16_t _heigth) const
{
	XmlParser args;

	if (!args.Initialize("tst_2.xml", { "ShowConsole", "Heigth", "Weigth"})) {
		return -1;
	}

	Window pWindow(_title, _weigth, _heigth);

	if ((int)pWindow.InitWindow() <= 0) { return -2; }

	while (WindowOpen) {
		pWindow.OnUpdate();
	}

	return 0;
}