#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "TVSet/CTVSet.h"

TEST_CASE("tv should be turned on first time on first chanel")
{
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("channel at turned off tv equals 0")
{
	CTVSet tv;
	tv.TurnOff();
	REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("select chanel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(5);
	REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("tv turn on at previous channel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(5);
	tv.TurnOff();
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("select chanel on turned off tv")
{
	CTVSet tv;
	tv.TurnOff();
	tv.SelectChannel(5);
	REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("select not available chanel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(5);
	tv.SelectChannel(100);
	REQUIRE(tv.GetChannel() == 5);
}