#include <iostream>
#include <string>

using namespace std;

struct htmlEntities
{
	pair<string, char> quot = { "&quot", '\"' };
	pair<string, char> apos = { "&apos", '\'' };
	pair<string, char> lt = { "&lt", '<' };
	pair<string, char> qt = { "&qt", '>"' };
	pair<string, char> amp = { "&amp", '&' };
};

string DecodeHtml(const string& html)
{

}

void DecodeHtmlInStream(istream& input, ostream& output)
{
	string line;
	while (getline(cin, line))
	{

	}
}

int main(int argc, char* argv[])
{
	DecodeHtmlInStream(cin, cout);
}