#include "CComplex.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <exception>
#include <limits>
#include <stdexcept>

CComplex::CComplex(double real, double image) : m_real(real), m_image(image)
{
}

double CComplex::Re() const
{
	return m_real;
}

double CComplex::Im() const
{
	return m_image;
}

double CComplex::GetMagnitude() const
{
	return sqrt(pow(m_real, 2) + pow(m_image, 2));
}

double CComplex::GetArgument() const
{
	return atan2(m_image, m_real);
}

CComplex CComplex::operator+(const CComplex& a) const
{
	return CComplex(m_real + a.m_real, m_image + a.m_image);
}

CComplex CComplex::operator-(const CComplex& a) const
{
	return CComplex(m_real - a.m_real, m_image - a.m_image);
}

CComplex CComplex::operator*(const CComplex& a) const
{
	double real = m_real * a.m_real - m_image * a.m_image;
	double image = m_real * a.m_image + m_image * a.m_real;
	return CComplex(real, image);
}

CComplex CComplex::operator/(const CComplex& a) const
{
	double denominator = pow(a.m_real, 2) + pow(a.m_image, 2);
	if (denominator == 0)
	{
		throw std::invalid_argument("division by zero");
	}
	double real = (m_real * a.m_real + m_image * a.m_image) / denominator;
	double image = (a.m_real * m_image - m_real * a.m_image) / denominator;
	return CComplex(real, image);
}

CComplex CComplex::operator+() const
{
	return *this;
}

CComplex CComplex::operator-() const
{
	return 0 - *this;
}

CComplex& CComplex::operator+=(const CComplex& a)
{
	m_real += a.m_real;
	m_image += a.m_image;
	return *this;
}

CComplex& CComplex::operator-=(const CComplex& a)
{
	m_real -= a.m_real;
	m_image -= a.m_image;
	return *this;
}

CComplex& CComplex::operator*=(const CComplex& a)
{
	CComplex b = *this * a;
	m_real = b.m_real;
	m_image = b.m_image;
	return *this;
}

CComplex& CComplex::operator/=(const CComplex& a)
{
	CComplex b = *this / a;
	m_real = b.m_real;
	m_image = b.m_image;
	return *this;
}

bool CComplex::operator==(const CComplex& a) const
{
	CComplex delta = *this - a;
	return fabs(delta.Re()) < DBL_EPSILON && fabs(delta.Im()) < DBL_EPSILON;
}

bool CComplex::operator!=(const CComplex& a) const
{
	return !(*this == a);
}

CComplex operator+(const double a, const CComplex& b)
{
	return b + a;
}

CComplex operator-(const double a, const CComplex& b)
{
	return CComplex(a) - b;
}

CComplex operator*(const double a, const CComplex& b)
{
	return b * a;
}

CComplex operator/(const double a, const CComplex& b)
{
	return CComplex(a) / b;
}

bool operator==(const double a, const CComplex& b)
{
	return b == a;
}

bool operator!=(const double a, const CComplex& b)
{
	return b != a;
}