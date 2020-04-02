#include "Decoder.h"

std::map<std::string, std::string> htmlEntities{ 
	{"&quot;", "\""}, 
	{ "&apos;", "\'" }, 
	{ "&lt;", "<" }, 
	{ "&gt;", ">" }, 
	{ "&amp;", "&" } };

std::string ReplaceSubString(const std::string& line, const std::string& searchString, const std::string& replaceString)
{
	std::string lineWithReplace;
	size_t lastPos = 0;

	if (searchString != "")
	{
		lastPos = 0;
		lineWithReplace = "";
		size_t foundPos = line.find(searchString);
		while (foundPos != std::string::npos)
		{
			lineWithReplace.append(line, lastPos, foundPos - lastPos);
			lineWithReplace.append(replaceString);
			lastPos = foundPos + searchString.length();
			foundPos = line.find(searchString, foundPos + searchString.length());
		}
	}
	lineWithReplace.append(line, lastPos, line.length() - lastPos);

	return lineWithReplace;
}

std::string DecodeHtml(const std::string& html)
{
	
	std::string decodeHtml = html;

	for (std::pair<std::string, std::string> htmlEntity : htmlEntities)
	{
		decodeHtml = ReplaceSubString(decodeHtml, htmlEntity.first, htmlEntity.second);
	}

	return decodeHtml;
}