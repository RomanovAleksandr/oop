#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "MiniDictionary/MiniDictionary/Translator.h"

using namespace std;


TEST_CASE("Find translation in empty dictionary")
{
	Dictionary dictionary;
	string translation = FindTranslation(dictionary, "cat");
	REQUIRE(translation == "");
}

TEST_CASE("Add translation to dictionary")
{
	Dictionary dictionary;
	AddTranslationToDictionaty(dictionary, "cat", "кот");
	string translation = FindTranslation(dictionary, "cat");
	REQUIRE(translation == "кот");
}

TEST_CASE("Read dictionary from stream")
{
	Dictionary dictionary;
	istringstream input("cat\nкот\nworld\nмир\n");
	ReadDictionaryFromStream(dictionary, input);
	Dictionary expectedDictionary{ {"cat", "кот"}, {"world", "мир"} };
	REQUIRE(dictionary == expectedDictionary);
}

TEST_CASE("Write dictionary to stream")
{
	ostringstream output;
	Dictionary dictionary{ {"cat", "кот"}, {"world", "мир"} };
	WriteDictionaryToStream(dictionary, output);
	string expectedOutput("cat\nкот\nworld\nмир\n");
	REQUIRE(output.str() == expectedOutput);
}