#include <iostream>
#include "CTVSet.h"

using namespace std;

void TurnOn(CTVSet& tv, ostream& output)
{
	if (!tv.IsTurnedOn())
	{
		tv.TurnOn();
		output << "TV is turned on\n";
	}
	else
	{
		output << "TV is already on\n";
	}
}

void TurnOff(CTVSet& tv, ostream& output)
{
	if (tv.IsTurnedOn())
	{
		tv.TurnOff();
		output << "TV is turned off\n";
	}
	else
	{
		output << "TV is already off\n";
	}
}

void SelectChannel(CTVSet& tv, istream& input, ostream& output)
{
	int channel;
	if (input >> channel)
	{
		if (!tv.IsTurnedOn())
		{
			output << "Error. TV is turned off\n";
			return;
		}
		else if (!tv.isAvailableChannel(channel))
		{
			output << "Error. Channel is out of allow range\n";
			return;
		}
		tv.SelectChannel(channel);
		output << "Selected channel " << channel << "\n";
	}
	else
	{
		output << "Error. Input error\n";
		input.clear();
	}
}

void PrintInfo(CTVSet& tv, ostream& output)
{
	output << "TV is turned " << (tv.IsTurnedOn() ? "on" : "off") << endl;
	output << "Current channel " << tv.GetChannel() << endl;
}

void TVController(istream& input, ostream& output)
{
	CTVSet tv;
	string command;
	while (cin >> command)
	{
		if (command == "TurnOn")
		{
			TurnOn(tv, output);
		}
		else if (command == "TurnOff")
		{
			TurnOff(tv, output);
		}
		else if (command == "SelectChannel")
		{
			SelectChannel(tv, input, output);
		}
		else if (command == "Info")
		{
			PrintInfo(tv, output);
		}
		else
		{
			output << "Unknown command, use: TurnOn, TurnOff, SelectChannel <channel number>, Info\n";
		}
	}
}

int main(int argc, char* argv[])
{
	TVController(cin, cout);
}