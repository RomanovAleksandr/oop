#include "CTVSet.h"

void CTVSet::TurnOn()
{
	m_isTurnedOn = true;
}

void CTVSet::TurnOff()
{
	m_isTurnedOn = false;
}

bool CTVSet::isAvailableChannel(int channel)
{
	return minChannel <= channel && channel <= maxChannel;
}

void CTVSet::SelectChannel(int channel)
{
	if (isAvailableChannel(channel) && m_isTurnedOn)
	{
		m_currentChannel = channel;
	}
}

int CTVSet::GetChannel()
{
	if (m_isTurnedOn)
	{
		return m_currentChannel;
	}
	return 0;
}

bool CTVSet::IsTurnedOn()
{
	return m_isTurnedOn;
}