#pragma once
#include "Translator.h"

using namespace std;

bool ReadDictionaryFromFile(Dictionary& dictionamry, const string& dictionaryFileNmae)
{
	ifstream input(dictionaryFileNmae);
	if (!input.is_open())
	{
		cout << "Failed to open " << dictionaryFileNmae << " for reading\n";
		return false;
	}

	string english;
	string russian;
	while (getline(input, english), getline(input, russian))
	{
		dictionamry.insert(make_pair(english, russian));
	}

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return false;
	}

	input.close();

	return true;
}

string FindTranslation(const Dictionary& dictionamry, const string& word)
{
	map<string, string>::const_iterator it = dictionamry.find(word);
	if (it != dictionamry.end())
	{
		return it->second;
	}
	else
	{
		return "";
	}
}

void AddTranslationToDictionaty(Dictionary& dictionamry, const string& word, const string& translation)
{
	dictionamry.insert(make_pair(word, translation));
}

bool SaveChangessToFile(const Dictionary& dictionamry, const string& dictionaryFileNmae)
{
	ofstream output(dictionaryFileNmae);
	if (!output.is_open())
	{
		cout << "Failed to open " << dictionaryFileNmae << " for writing\n";
		return false;
	}

	for (const auto& [english, russian] : dictionamry)
	{
		output << english << endl;
		output << russian << endl;
	}

	if (output.flush())
	{
		cout << "Failed to write data to dictionary file\n";
		return false;
	}

	output.close();

	return true;
}