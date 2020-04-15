#pragma once
#include "Translator.h"

using namespace std;

bool ReadDictionaryFromFile(map<string, string>& dictionamry, const string& dictionaryFileNmae)
{
	ifstream input(dictionaryFileNmae);
	if (!input.is_open())
	{
		cout << "Failed to open " << dictionaryFileNmae << " for reading\n";
		return false;
	}

	return 1;
}

bool Translate(istream& input, ostream& output, string& dictionaryFileNmae)
{
	map<string, string> dictionary;
	if (!ReadDictionaryFromFile(dictionary, dictionaryFileNmae))
	{
		return 0;
	}
	return 1;
}