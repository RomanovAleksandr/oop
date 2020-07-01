#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "HttpUrl/CHttpUrl.h"

TEST_CASE("CHttpUrl(string)")
{
	SECTION("full url")
	{
		CHttpUrl url("http://www.testsite.com:1337/123/doc.html");
		REQUIRE(url.GetDomain() == "www.testsite.com");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetPort() == 1337);
		REQUIRE(url.GetDocument() == "/123/doc.html");
		REQUIRE(url.GetURL() == "http://www.testsite.com/123/doc.html");
	}

	SECTION("url without port")
	{
		CHttpUrl url("http://testsite.com/123/doc.html");
		REQUIRE(url.GetDomain() == "testsite.com");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetPort() == 80);
		REQUIRE(url.GetDocument() == "/123/doc.html");
		REQUIRE(url.GetURL() == "http://testsite.com/123/doc.html");
	}
	
	SECTION("url without port and document")
	{
		CHttpUrl url("https://testsite.com");
		REQUIRE(url.GetDomain() == "testsite.com");
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetPort() == 443);
		REQUIRE(url.GetDocument() == "/");
		REQUIRE(url.GetURL() == "https://testsite.com/");
	}

	SECTION("incorrect urls")
	{
		REQUIRE_THROWS(CHttpUrl("http:/test.com"));
		REQUIRE_THROWS(CHttpUrl("ftp:/test.com"));
		REQUIRE_THROWS(CHttpUrl("https:/test.com:999999"));
	}
}

TEST_CASE("CHttpUrl(domain, document, protocol)")
{
	SECTION("correct url")
	{
		CHttpUrl url("testsite.com", "/doc.html", Protocol::HTTP);
		REQUIRE(url.GetDomain() == "testsite.com");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetPort() == 80);
		REQUIRE(url.GetDocument() == "/doc.html");
		REQUIRE(url.GetURL() == "http://testsite.com/doc.html");
	}

	SECTION("add /")
	{
		CHttpUrl url("testsite.com", "doc.html", Protocol::HTTP);
		REQUIRE(url.GetDocument() == "/doc.html");
	}

	SECTION("empty domain")
	{
		REQUIRE_THROWS(CHttpUrl("", "doc.html", Protocol::HTTP));
	}
}

TEST_CASE("CHttpUrl(domain, document, protocol, port)")
{
	SECTION("correct url")
	{
		CHttpUrl url("testsite.com", "/doc.html", Protocol::HTTP, 1337);
		REQUIRE(url.GetDomain() == "testsite.com");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetPort() == 1337);
		REQUIRE(url.GetDocument() == "/doc.html");
		REQUIRE(url.GetURL() == "http://testsite.com/doc.html");
	}

	SECTION("incorrect port")
	{
		REQUIRE_THROWS(CHttpUrl("testsite.com", "doc.html", Protocol::HTTP, 65536));
	}

	SECTION("add /")
	{
		CHttpUrl url("testsite.com", "doc.html", Protocol::HTTP, 1);
		REQUIRE(url.GetDocument() == "/doc.html");
	}

	SECTION("empty domain")
	{
		REQUIRE_THROWS(CHttpUrl("", "doc.html", Protocol::HTTP, 1));
	}
}