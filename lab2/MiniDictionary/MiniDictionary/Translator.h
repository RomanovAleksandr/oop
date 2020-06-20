#pragma once
#include <string>
#include <map>

typedef std::map<std::string, std::string> Dictionary;

bool ReadDictionaryFromFile(Dictionary& dictionary, const std::string& dictionaryFileNmae);
void ReadDictionaryFromStream(Dictionary& dictionary, std::istream& input);
std::string FindTranslation(const Dictionary& dictionary, const std::string& word);
void AddTranslationToDictionaty(Dictionary& dictionary, const std::string& word, const std::string& translation);
bool SaveChangessToFile(const Dictionary& dictionary, const std::string& dictionaryFileNmae);
void WriteDictionaryToStream(const Dictionary& dictionary, std::ostream& output);