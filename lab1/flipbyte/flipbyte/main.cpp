#include <iostream>
#include <string>
#include <optional>
#include <cstdint>

using namespace std;

struct Args
{
	byte input;
};

bool CheckRange(int number)
{
	if (number < 0 || number > 255)
	{
		cout << "wrong range, must be 0-255\n";
		return 0;
	}

	return 1;
}

bool GetByte(const string& input, byte& b)
{
	int inputNumber;
	size_t badIndex = 0;
	try
	{
		inputNumber = stoi(input, &badIndex, 10);
	}
	catch (const std::exception& e)
	{
		cout << "Invalid argumen\n";
		cout << e.what() << '\n';
		return 0;
	}

	if (badIndex != input.length())
	{
		cout << "Input is not number\n";
		cout << "Bad index " << badIndex + 1 << '\n';
		return 0;
	}

	if (!CheckRange(inputNumber))
	{
		return 0;
	}

	b = (byte)inputNumber;

	return 1;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: flipbyte.exe <input byte>\n";
		return std::nullopt;
	}

	Args args;
	if (!GetByte(argv[1], args.input))
	{
		return std::nullopt;
	}

	return args;
}

int ReverseByte(uint8_t number)
{
	uint8_t converted = 0;
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

	int converted = ReverseByte((uint8_t)args->input);
	cout << converted << "\n";
}