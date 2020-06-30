#include <iostream>
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

using namespace std;

int main()
{
	std::string input;
	while (getline(std::cin, input))
	{
		try
		{
			CHttpUrl url(input);
			cout << "URL: " << url.GetURL() << endl
				<< "Protocol: " << url.GetStrProtocol() << endl
				<< "Domain: " << url.GetDomain() << endl
				<< "Port: " << url.GetPort() << endl
				<< "Document: " << url.GetDocument() << endl;
		}
		catch (invalid_argument& exception)
		{
			cout << exception.what() << endl;
		}
	}
}