#ifndef LAUNCHER_HPP_
#define LAUNCHER_HPP_

#include "XMLParse.hpp"

#include <iostream>
#include <memory>

class Launcher 
{
public:
	Launcher() = default;

	~Launcher() = default;
private:
	//bool Init(const char* _title, const uint16_t _weigth, const uint16_t _heigth);

	bool Init();
public:
	int Start();
private:
	std::unique_ptr<class Window> pWindow;
	bool is_init;
};

#endif // !LAUNCHER_HPP_
