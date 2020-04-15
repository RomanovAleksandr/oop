#include <iostream>
#include <optional>
#include "Translator.h"

using namespace std;

struct Args
{
	string dictionaryFileNmae;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: MiniDictionary.exe <dictionary file>\n";
		return nullopt;
	}
	Args args;
	args.dictionaryFileNmae = argv[1];
	return args;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	if (!Translate(cin, cout, args->dictionaryFileNmae))
	{
		return 1;
	}
}