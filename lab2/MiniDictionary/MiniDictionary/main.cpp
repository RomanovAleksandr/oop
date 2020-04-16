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

bool Translate(istream& input, ostream& output, const string& dictionaryFileNmae)
{
	Dictionary dictionary;
	if (!ReadDictionaryFromFile(dictionary, dictionaryFileNmae))
	{
		return false;
	}

	string word;
	bool newWordsAdded = false;
	while (getline(input, word))
	{
		if (word != "...")
		{
			if (word == "")
			{
				continue;
			}
			string translatedWord = FindTranslation(dictionary, word);
			if (translatedWord != "")
			{
				output << translatedWord << endl;
			}
			else
			{
				cout << "Неизвестное слово “" << word << "”. Введите перевод или пустую строку для отказа." << endl;
				string translation;
				getline(input, translation);
				if (translation != "")
				{
					newWordsAdded = true;
					AddTranslationToDictionaty(dictionary, word, translation);
					cout << "Слово “" << word << "” сохранено в словаре как “" << translation << "”." << endl;
				}
				else
				{
					cout << "Слово “" << word << "”проигнорировано." << endl;
				}
			}
		}
		else
		{
			if (newWordsAdded)
			{
				cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;
				string answer;
				getline(input, answer);
				if (answer == "Y" || answer == "y")
				{
					if (!SaveChangessToFile(dictionary, dictionaryFileNmae))
					{
						return false;
					}
					cout << "Изменения сохранены. До свидания." << endl;
				}
			}
			break;
		}
	}

	return true;
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