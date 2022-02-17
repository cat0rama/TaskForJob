#include "XMLParse.hpp"
#include "Log.hpp"

XmlParser::XmlParser(): file_path(nullptr)
{	}

std::string XmlParser::GetStrFromChild(const tinyxml2::XMLElement* _elem, const char* _child_name) const //get string from child parameter
{
	if (_elem != nullptr) {
		auto str = _elem->FirstChildElement(_child_name)->GetText();	//get child element from _elem
		return str == NULL ? "Element " + std::string(_child_name) + " not found!" : str;	
	} else {
		return "Element is nullptr";
	}
}

bool XmlParser::Initialize(const char* _file_path, std::vector<std::string> _basic_names)	//initialize lib
{
	this->file_path = _file_path;
	this->elem_names = std::move(_basic_names);
	
	if (doc.LoadFile(_file_path) != tinyxml2::XML_SUCCESS) {	//load file from path
		LOG_CRITICAL("SETTINGS FILE NOT LOADED!");
		return false;
	}
	return true;
}

std::string XmlParser::GetParameter(const char* _param_name) const	//get parameters from file which initialize in XmlParser::Initialize method
{
	auto pRoot = doc.RootElement();

	if (pRoot != nullptr) {
		return GetStrFromChild(pRoot, _param_name);
	} else {
		return "Element not found!";
	}
}

void XmlParser::PrintParams() const  //print all xml elements which handed over user in initialize procces 
{
	auto pRoot = doc.RootElement();	//get Root element of file

	if (pRoot != nullptr) {
		auto pElems = doc.FirstChildElement();	//get first element of settings
		while (pElems) {
			for (const auto& elems : elem_names) {
				LOG_INFO("{0} : {1}", elems, GetStrFromChild(pElems, elems.c_str())); //print elements
			}
			pElems = pElems->NextSiblingElement(); //next element
		}
	} else {
		LOG_CRITICAL("XML({0}) FILE NOT RECOGNIZED", file_path);
	}
}