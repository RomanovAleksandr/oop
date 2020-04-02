#include "Decoder.h"

std::string DecodeHtml(const std::string& html)
{
	std::map<std::string, std::string> htmlEntities{ {"&quot;", "\""}, { "&apos;", "\'" }, { "&lt;", "<" }, { "&gt;", ">" }, { "&amp;", "&" } };
	std::string decodeHtml;
	size_t lastPos = 0;

	while (true)
	{
		size_t firstPos = std::string::npos;
		std::pair<std::string, std::string> currentEntity = { "", "" };

		for (std::pair<std::string, std::string> htmlEntity : htmlEntities)
		{
			size_t foundPos = html.find(htmlEntity.first, lastPos);
			if (foundPos < firstPos)
			{
				firstPos = foundPos;
				currentEntity = htmlEntity;
			}
		}

		if (firstPos != std::string::npos)
		{
			decodeHtml.append(html, lastPos, firstPos - lastPos);
			decodeHtml.append(currentEntity.second);
			lastPos = firstPos + currentEntity.first.length();
		}
		else
		{
			break;
		}
	}

	decodeHtml.append(html, lastPos, html.length() - lastPos);

	return decodeHtml;
}