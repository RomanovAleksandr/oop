#include <iostream>
#include <fstream>
#include <string>
#include <optional>

using namespace std;

struct Args
{
	string inputFileName;
	string outputFileName;
	string searchString;
	string replaceString;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	args.searchString = argv[3];
	args.replaceString = argv[4];
	return args;
}

void ReplaceSubString(ifstream& input, ofstream& output, string searchString, string replaceString)
{
	string line;
	while (getline(input, line))
	{
		string newLine = "";
		int lastPos = 0;
		if (searchString != "")
		{
			lastPos = 0;
			newLine = "";
			size_t foundPos = line.find(searchString);
			while (foundPos != string::npos)
			{
				newLine.append(line, lastPos, foundPos - lastPos);
				newLine.append(replaceString);
				lastPos = foundPos + searchString.length();
				foundPos = line.find(searchString, foundPos + searchString.length());
			}
		}
		newLine.append(line, lastPos, line.length() - lastPos);
		output << newLine << "\n";
	}

}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	ifstream input(args->inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open " << args->inputFileName << " for reading\n";
		return 1;
	}

	ofstream output(args->outputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open " << args->outputFileName << " for writing\n";
		return 1;
	}

	ReplaceSubString(input, output, args->searchString, args->replaceString);

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return 1;
	}

	if (!output.flush())
	{
		cout << "Failed to write data to output file\n";
		return 1;
	}
}