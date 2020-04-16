#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <optional>

using namespace std;

typedef std::map<std::string, std::string> Dictionary;

bool ReadDictionaryFromFile(Dictionary& dictionamry, const string& dictionaryFileNmae);
string FindTranslation(const Dictionary& dictionamry, const string& word);
void AddTranslationToDictionaty(Dictionary& dictionamry, const string& word, const string& translation);
bool SaveChangessToFile(const Dictionary& dictionamry, const string& dictionaryFileNmae);