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
public:
	bool Initialize(const char* _file_path, std::vector<std::string> _basic_names);

	std::string GetStrFromChild(const XMLElement* _elem, const char* _child_name) const;
private:
	std::vector<std::string> elem_names;
	const char* file_path;
	XMLDocument doc;
};

#endif // !XML_PARSER_HPP_
