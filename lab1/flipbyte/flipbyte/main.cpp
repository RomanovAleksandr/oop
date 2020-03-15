#include <iostream>
#include <string>
#include <optional>

using namespace std;

struct Args
{
	string input;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: flipbyte.exe <input byte>\n";
		return std::nullopt;
	}
	Args args;
	args.input = argv[1];
	return args;
}

int GetInt(string input)
{
	if (input.length() == 0)
	{
		cout << "Invalid input length";
		return -1;
	}

	for (int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			cout << "Input is not positive number\n";
			return -1;
		}
	}
	int number = stoi(input, nullptr, 10);
	return number;
}

bool CheckNumber(int number)
{
	
	if (number < 0 || number > 255)
	{
		cout << "wrong range, must be 0-255";
		return 0;
	}
	return 1;
}

int ReverseByte(int number)
{
	int converted = 0;
	for (int i = 0; i < 8; i++)
	{
		int bit = number & 1;
		converted = converted << 1;
		converted = converted | bit;
		number = number >> 1;
	}
	return converted;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	string input = args->input;

	int number = GetInt(input);
	if (!CheckNumber(number))
	{
		return 1;
	}

	int converted = ReverseByte(number);
	cout << converted << "\n";
}