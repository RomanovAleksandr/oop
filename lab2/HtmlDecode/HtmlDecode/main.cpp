#include <iostream>
#include <string>
#include <map>
#include "Decoder.h"

using namespace std;

void DecodeHtmlStream(istream& input, ostream& output)
{
	string line;
	while (getline(cin, line))
	{
		cout << DecodeHtml(line) << endl;
	}
}

int main(int argc, char* argv[])
{
	DecodeHtmlStream(cin, cout);
}