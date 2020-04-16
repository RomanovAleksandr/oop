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

	string line;
	string line2;
	while (getline(input, line), getline(input, line2))
	{
		dictionamry.insert(make_pair(line, line2));
	}

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return false;
	}

	return true;
}

optional<string> FindTranslation(map<string, string>& dictionamry, const string& word)
{
	map<string, string>::iterator it = dictionamry.find(word);
	if (it != dictionamry.end())
	{
		return it->second;
	}
	else
	{
		return nullopt;
	}
}

bool Translate(istream& input, ostream& output, const string& dictionaryFileNmae)
{
	map<string, string> dictionary;
	if (!ReadDictionaryFromFile(dictionary, dictionaryFileNmae))
	{
		return false;
	}

	string line;
	while (getline(input, line))
	{
		if (line != "...")
		{
			auto translatedWord = FindTranslation(dictionary, line);
			if (translatedWord)
			{
				cout << translatedWord.value() << endl;
			}
		}
		else
		{
			break;
		}
	}

	return true;
}