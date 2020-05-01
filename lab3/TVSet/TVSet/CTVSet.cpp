#include "CTVSet.h"

void CTVSet::TurnOn()
{
	m_isTurnedOn = true;
}

void CTVSet::TurnOff()
{
	m_isTurnedOn = false;
}

bool CTVSet::isAvailableChannel(const int channel) const
{
	return m_minChannel <= channel && channel <= m_maxChannel;
}

void CTVSet::SelectChannel(const int channel)
{
	if (isAvailableChannel(channel) && m_isTurnedOn)
	{
		m_currentChannel = channel;
	}
}

int CTVSet::GetChannel() const
{
	if (m_isTurnedOn)
	{
		return m_currentChannel;
	}
	return 0;
}

bool CTVSet::IsTurnedOn() const
{
	return m_isTurnedOn;
}