#ifndef XML_PARSER_HPP_
#define XML_PARSER_HPP_

#include <tinyxml2.h>
#include <vector>
#include <string>

using namespace tinyxml2;

class XmlParser
{
public:
	XmlParser();

	~XmlParser() = default;
private:
	std::string GetStrFromChild(const XMLElement* _elem, const char* _child_name) const;
public:
	bool Initialize(const char* _file_path, std::vector<std::string> _basic_names);

	std::string GetParameter(const char* _param_name) const;

	void PrintParams() const;
private:
	std::vector<std::string> elem_names;
	const char* file_path;
	XMLDocument doc;
};

#endif // !XML_PARSER_HPP_
