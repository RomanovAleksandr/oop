#include <iostream>
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