#pragma once

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	void SelectChannel(const int channel);
	int GetChannel();
	bool IsTurnedOn();
	bool isAvailableChannel(const int channel);
	
private:
	int m_currentChannel = 1;
	bool m_isTurnedOn = false;
	const int m_minChannel = 1;
	const int m_maxChannel = 99;
};