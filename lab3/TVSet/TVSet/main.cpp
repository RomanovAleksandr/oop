#include <iostream>
#include "CTVSet.h"

using namespace std;

void TVController(istream& input, ostream& output)
{
	CTVSet tv;
	string command;
	while (cin >> command)
	{
		if (command == "TurnOn")
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
		else if (command == "TurnOff")
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
		else if (command == "SelectChannel")
		{
			int channel;
			if (input >> channel)
			{
				if (!tv.IsTurnedOn())
				{
					output << "Error. TV is turned off\n";
					continue;
				}
				else if (!tv.isAvailableChannel(channel))
				{
					output << "Error. Channel is out of allow range\n";
					continue;
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
		else if (command == "Info")
		{
			output << "TV is turned " << (tv.IsTurnedOn() ? "on" : "off") << endl;
			output << "Current channel " << tv.GetChannel() << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	TVController(cin, cout);
}