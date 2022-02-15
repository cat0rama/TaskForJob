#ifndef XML_PARSER_HPP_
#define XML_PARSER_HPP_

#include <tinyxml2.h>
#include <vector>
#include <string>

class XmlParser
{
public:
	XmlParser();

	~XmlParser() = default;
private:
	std::string GetStrFromChild(const tinyxml2::XMLElement* _elem, const char* _child_name) const;
public:
	bool Initialize(const char* _file_path, std::vector<std::string> _basic_names);

	std::string GetParameter(const char* _param_name) const;

	void PrintParams() const;
private:
	std::vector<std::string> elem_names;
	tinyxml2::XMLDocument doc;
	const char* file_path;
};

#endif // !XML_PARSER_HPP_
