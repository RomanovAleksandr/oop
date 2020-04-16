#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <optional>

bool Translate(std::istream& input, std::ostream& output, const std::string& dictionaryFileNmae);
//bool ReadDictionaryFromFile(std::map<std::string, std::string>& dictionamry, const std::string& dictionaryFileNmae);