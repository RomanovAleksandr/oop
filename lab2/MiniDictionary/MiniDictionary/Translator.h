#pragma once
#include <iostream>
#include <fstream>
#include <map>

bool Translate(std::istream& input, std::ostream& output, std::string& dictionaryFileNmae);
bool ReadDictionaryFromFile(std::map<std::string, std::string>& dictionamry, const std::string& dictionaryFileNmae);