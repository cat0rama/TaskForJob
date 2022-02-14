#ifndef LAUNCHER_HPP_
#define LAUNCHER_HPP_

#include "Window.hpp"
#include "XMLParse.hpp"

#include <memory>

class Launcher final
{
public:
	Launcher() = default;

	~Launcher() = default;
public:
	int Start(const char* _title, const uint16_t _weigth, const uint16_t _heigth);
};

#endif // !LAUNCHER_HPP_
