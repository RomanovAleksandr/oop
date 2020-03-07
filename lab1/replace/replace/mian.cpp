#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return 1;
	}

	ifstream input(argv[1]);
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ofstream output(argv[2]);
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	string line;
	string searchStr = argv[3];
	string replaceStr = argv[4];

	while (getline(input, line))
	{
		if (searchStr != "")
		{
			size_t foundPos = line.find(searchStr);
			while (foundPos != string::npos)
			{
				line.erase(foundPos, searchStr.length());
				line.insert(foundPos, replaceStr);
				foundPos = line.find(searchStr, foundPos + replaceStr.length());
			}
		}
		output << line << "\n";
	}

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