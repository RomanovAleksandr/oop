#pragma once
#include <string>

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = HTTP);
	
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);

	std::string GetURL()const;
	std::string GetDomain()const;
	std::string GetDocument()const;
	Protocol GetProtocol()const;
	unsigned short GetPort()const;
	std::string GetStrProtocol() const;

private:
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;

	static Protocol ParseProtocol(std::string protocol);
	static unsigned short ParsePort(std::string const& port, Protocol& protocol);
	static std::string SetDocument(const std::string& document);
	static bool IsCorrectPort(unsigned short port);
	static unsigned short GetDefaultPort(Protocol protocol);
	void SetDomain(std::string const& domain);
	static const unsigned short PORT_HTTP = 80;
	static const unsigned short PORT_HTTPS = 443;
};