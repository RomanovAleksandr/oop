#pragma once
#include "Translator.h"
#include <fstream>
#include <iostream>

using namespace std;

void ReadDictionaryFromStream(Dictionary& dictionary, std::istream& input)
{
	string english;
	string russian;
	while (getline(input, english), getline(input, russian))
	{
		dictionary.emplace(english, russian);
	}
}

bool ReadDictionaryFromFile(Dictionary& dictionary, const string& dictionaryFileNmae)
{
	ifstream input(dictionaryFileNmae);
	if (!input.is_open())
	{
		ofstream dictionaryFile(dictionaryFileNmae);
		return true;
	}

	dictionary.clear();

	ReadDictionaryFromStream(dictionary, input);

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return false;
	}

	return true;
}

string FindTranslation(const Dictionary& dictionary, const string& word)
{
	map<string, string>::const_iterator it = dictionary.find(word);
	if (it != dictionary.end())
	{
		return it->second;
	}
	else
	{
		return "";
	}
}

void AddTranslationToDictionaty(Dictionary& dictionary, const string& word, const string& translation)
{
	dictionary.emplace(word, translation);
}

void WriteDictionaryToStream(const Dictionary& dictionary, std::ostream& output)
{
	for (const auto& [english, russian] : dictionary)
	{
		output << english << endl;
		output << russian << endl;
	}
}

bool SaveChangessToFile(const Dictionary& dictionary, const string& dictionaryFileNmae)
{
	ofstream output(dictionaryFileNmae);
	if (!output.is_open())
	{
		cout << "Failed to open " << dictionaryFileNmae << " for writing\n";
		return false;
	}

	WriteDictionaryToStream(dictionary, output);

	if (!output.flush())
	{
		cout << "Failed to write data to dictionary file\n";
		return false;
	}

	return true;
}