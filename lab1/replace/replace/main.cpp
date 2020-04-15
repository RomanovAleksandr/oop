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

string ReplaceSubString(const string& line, const string& searchString, const string& replaceString)
{
	string lineWithReplace;
	size_t lastPos = 0;

	if (searchString != "")
	{
		size_t foundPos = line.find(searchString);
		while (foundPos != string::npos)
		{
			lineWithReplace.append(line, lastPos, foundPos - lastPos);
			lineWithReplace.append(replaceString);
			lastPos = foundPos + searchString.length();
			foundPos = line.find(searchString, foundPos + searchString.length());
		}
	}
	lineWithReplace.append(line, lastPos, line.length() - lastPos);

	return lineWithReplace;
}

bool CopyFileWithReplace(const string& inputFileName, const string& outputFileName, const string& searchString, const string& replaceString)
{
	ifstream input(inputFileName);
	ofstream output(outputFileName);

	if (!input.is_open())
	{
		cout << "Failed to open " << inputFileName << " for reading\n";
		return false;
	}

	if (!output.is_open())
	{
		cout << "Failed to open " << outputFileName << " for writing\n";
		return false;
	}

	string line;

	while (getline(input, line))
	{
		output << ReplaceSubString(line, searchString, replaceString) << "\n";
	}

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return false;
	}

	if (!output.flush())
	{
		cout << "Failed to write data to output file\n";
		return false;
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

	if (!CopyFileWithReplace(args->inputFileName, args->outputFileName, args->searchString, args->replaceString))
	{
		return 1;
	}

	return 0;
}