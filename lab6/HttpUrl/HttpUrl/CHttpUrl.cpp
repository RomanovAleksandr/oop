#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <regex>

using namespace std;

CHttpUrl::CHttpUrl(string const& url)
{
	smatch matches;
	regex rx("^(.*)://([A-Za-z0-9\\-\\.]+)(:([0-9]+))?(/(.*))?$");
	regex_search(url, matches, rx);
	if (matches.empty())
	{
		throw CUrlParsingError("Invalid url");
	}
	m_protocol = ParseProtocol(matches[1]);
	m_port = ParsePort(matches[4], m_protocol);
	m_domain = matches[2];
	m_document = SetDocument(matches[6]);
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
{
	SetDomain(domain);
	m_document = SetDocument(document);
	m_protocol = protocol;
	m_port = GetDefaultPort(protocol);
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)
{
	SetDomain(domain);
	m_document = SetDocument(document);
	m_protocol = protocol;
	if (!IsCorrectPort(port))
	{
		throw invalid_argument("Incorrect port");
	}
	m_port = port;
}

Protocol CHttpUrl::ParseProtocol(string protocol)
{
	transform(protocol.begin(), protocol.end(), protocol.begin(), tolower);
	if (protocol == "http")
	{
		return Protocol::HTTP;
	}
	else if (protocol == "https")
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw invalid_argument("Undefined protocol");
	}
}

unsigned short CHttpUrl::ParsePort(string const& port, Protocol& protocol)
{
	if (!port.empty())
	{
		int resultPort = atoi(port.c_str());
		if (IsCorrectPort(resultPort))
		{
			return resultPort;
		}
		else
		{
			throw invalid_argument("Incorrect port");
		}
	}
	return GetDefaultPort(protocol);
}

bool CHttpUrl::IsCorrectPort(int port)
{
	return 1 <= port && port <= 65535;
}

unsigned short CHttpUrl::GetDefaultPort(Protocol protocol)
{
	if (protocol == Protocol::HTTP)
	{
		return CHttpUrl::PORT_HTTP;
	}
	else if (protocol == Protocol::HTTPS)
	{
		return CHttpUrl::PORT_HTTPS;
	}
	else
	{
		throw std::runtime_error("Protocol doesn't have default port");
	}
}

string CHttpUrl::SetDocument(string const& document)
{
	if (document.empty() || document[0] != '/')
	{
		return '/' + document;
	}
	return document;
}

void CHttpUrl::SetDomain(std::string const& domain)
{
	if (domain.empty())
	{
		throw invalid_argument("Empty domain");
	}
	m_domain = domain;
}

string CHttpUrl::GetURL() const
{
	string url = GetStrProtocol() + "://" += m_domain;
	if (!GetDefaultPort(m_protocol))
	{
		url += ":" + to_string(m_port);
	}
	url += m_document;
	return url;
}

string CHttpUrl::GetStrProtocol() const
{
	if (m_protocol == Protocol::HTTP)
	{
		return "http";
	}
	if (m_protocol == Protocol::HTTPS)
	{
		return "https";
	}
	throw invalid_argument("Undefined protocol");
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}