#define CATCH_CONFIG_MAIN
#define _USE_MATH_DEFINES
#include "catch2/catch.hpp"
#include "Complex/CComplex.h"
#include <cmath>

TEST_CASE("CComplex")
{
	CComplex complex(-1, 2);
	REQUIRE(complex.Re() == -1);
	REQUIRE(complex.Im() == 2);
	REQUIRE(complex.GetMagnitude() == sqrt(5));
}

TEST_CASE("CComplex binary operator +")
{
	const CComplex a(2, 2);
	const CComplex b(1, 1);

	CComplex c = a + b;
	REQUIRE(c.Re() == 3);
	REQUIRE(c.Im() == 3);

	CComplex d = a + 1;
	REQUIRE(d.Re() == 3);
	REQUIRE(d.Im() == 2);

	CComplex e = 1 + a;
	REQUIRE(e.Re() == 3);
	REQUIRE(e.Im() == 2);
}

TEST_CASE("CComplex binary operator -")
{
	const CComplex a(2, 2);
	const CComplex b(1, 1);

	CComplex c = a - b;
	REQUIRE(c.Re() == 1);
	REQUIRE(c.Im() == 1);

	CComplex d = a - 1;
	REQUIRE(d.Re() == 1);
	REQUIRE(d.Im() == 2);

	CComplex e = 1 - a;
	REQUIRE(e.Re() == -1);
	REQUIRE(e.Im() == -2);
}

TEST_CASE("CComplex binary operator *")
{
	const CComplex a(2, 2);
	const CComplex b(1, 1);

	CComplex c = a * b;
	REQUIRE(c.Re() == 0);
	REQUIRE(c.Im() == 4);

	CComplex d = a * 1;
	REQUIRE(d.Re() == 2);
	REQUIRE(d.Im() == 2);

	CComplex e = 1 * a;
	REQUIRE(e.Re() == 2);
	REQUIRE(e.Im() == 2);

	CComplex f = 2 * a;
	REQUIRE(f.Re() == 4);
	REQUIRE(f.Im() == 4);


	REQUIRE_THROWS(a / 0);
}

TEST_CASE("CComplex binary operator /")
{
	const CComplex a(2, 2);
	const CComplex b(1, 1);

	CComplex c = a / b;
	REQUIRE(c.Re() == 2);
	REQUIRE(c.Im() == 0);

	CComplex d = a / 1;
	REQUIRE(d.Re() == 2);
	REQUIRE(d.Im() == 2);

	CComplex e = 1 / a;
	REQUIRE(e.Re() == 0.25);
	REQUIRE(e.Im() == -0.25);

	REQUIRE_THROWS(a / 0);
}

TEST_CASE("unary operator +")
{
	const CComplex a(2, 2);
	CComplex c = +a;
	REQUIRE(c.Re() == 2);
	REQUIRE(c.Im() == 2);
}

TEST_CASE("unary operator -")
{
	const CComplex a(2, 2);
	CComplex c = -a;
	REQUIRE(c.Re() == -2);
	REQUIRE(c.Im() == -2);
}

TEST_CASE("operator +=")
{
	CComplex c(2, 2);
	const CComplex b(1, 1);
	c += b;
	REQUIRE(c.Re() == 3);
	REQUIRE(c.Im() == 3);

	CComplex e(2, 2);
	e += 1;
	REQUIRE(e.Re() == 3);
	REQUIRE(e.Im() == 2);

	CComplex a(1, 0);
	(a += 2) += 3;
	CHECK(a.Re() == 6);
}

TEST_CASE("operator -=")
{
	CComplex c(2, 2);
	const CComplex b(1, 1);
	c -= b;
	REQUIRE(c.Re() == 1);
	REQUIRE(c.Im() == 1);

	CComplex e(2, 2);
	e -= 1;
	REQUIRE(e.Re() == 1);
	REQUIRE(e.Im() == 2);
}

TEST_CASE("operator *=")
{
	CComplex c(2, 2);
	const CComplex b(1, 1);
	c *= b;
	REQUIRE(c.Re() == 0);
	REQUIRE(c.Im() == 4);

	CComplex e(2, 2);
	e *= 2;
	REQUIRE(e.Re() == 4);
	REQUIRE(e.Im() == 4);
}

TEST_CASE("operator /=")
{
	CComplex c(2, 2);
	const CComplex b(1, 1);
	c /= b;
	REQUIRE(c.Re() == 2);
	REQUIRE(c.Im() == 0);

	CComplex e(2, 2);
	e /= 2;
	REQUIRE(e.Re() == 1);
	REQUIRE(e.Im() == 1);
}

TEST_CASE("operator ==")
{
	const CComplex a(2, 2);
	const CComplex b(1, 1);
	REQUIRE(a == a);
	REQUIRE(!(a == b));

	CComplex c(1, 0);
	REQUIRE(!(a == 1));
	REQUIRE(c == 1);
	REQUIRE(!(1 == a));
	REQUIRE(1 == c);
}

TEST_CASE("operator !=")
{
	const CComplex a(2, 2);
	const CComplex b(1, 1);
	REQUIRE(!(a != a));
	REQUIRE(a != b);

	CComplex c(1, 0);
	REQUIRE(a != 1);
	REQUIRE(!(c != 1));
	REQUIRE(1 != a);
	REQUIRE(!(1 != c));
}