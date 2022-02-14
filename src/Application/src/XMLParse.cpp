#include "XMLParse.hpp"
#include "Log.hpp"

XmlParser::XmlParser(): file_path(nullptr)
{	}

bool XmlParser::Initialize(const char* _file_path, std::vector<std::string> _basic_names)
{
	this->file_path = _file_path;
	this->elem_names = std::move(_basic_names);
	
	if (!doc.LoadFile(_file_path)) {
		LOG_CRITICAL("SETTINGS FILE NOT LOADED!");
		return false;
	}
	return true;
}

std::string XmlParser::GetStrFromChild(const XMLElement* _elem, const char* _child_name) const
{
	auto str = _elem->FirstChildElement(_child_name)->GetText();

	return str == NULL ? "element " + std::string(_child_name) + " not found!" : str;
}

