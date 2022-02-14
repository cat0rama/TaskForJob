#include "XMLParse.hpp"
#include "Log.hpp"

XmlParser::XmlParser(): file_path(nullptr)
{	}

std::string XmlParser::GetStrFromChild(const XMLElement* _elem, const char* _child_name) const
{
	auto str = _elem->FirstChildElement(_child_name)->GetText();

	return str == NULL ? "Element " + std::string(_child_name) + " not found!" : str;
}

bool XmlParser::Initialize(const char* _file_path, std::vector<std::string> _basic_names)
{
	this->file_path = _file_path;
	this->elem_names = std::move(_basic_names);
	
	if (doc.LoadFile(_file_path) != XML_SUCCESS) {
		LOG_CRITICAL("SETTINGS FILE NOT LOADED!");
		return false;
	}
	return true;
}

std::string XmlParser::GetParameter(const char* _param_name) const
{
	auto pRoot = doc.RootElement();

	if (pRoot != nullptr) {
		return GetStrFromChild(pRoot, _param_name);;
	} else {
		return "Element not found!";
	}
}

void XmlParser::PrintParams() const
{
	auto pRoot = doc.RootElement();

	if (pRoot != nullptr) {
		auto pElems = doc.FirstChildElement();
		while (pElems) {
			for (const auto& elems : elem_names) {
				LOG_INFO("{0} : {1}", elems, GetStrFromChild(pElems, elems.c_str()));
			}
			pElems = pElems->NextSiblingElement();
		}
	} else {
		LOG_CRITICAL("XML({0}) FILE NOT RECOGNIZED", file_path);
	}
}