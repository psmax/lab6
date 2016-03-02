#include "stdafx.h"
#include <stdexcept>
#include "Triangle.h"

CTriangle::CTriangle(double side1, double side2, double side3)
{
	if (side1 < 0 || side2 < 0 || side3 < 0)
	{
		throw std::invalid_argument("triangle sides can't be negative");
	}

	if (side1 >= side2 + side3 ||
		side2 >= side1 + side3 ||
		side3 >= side1 + side2)
	{
		throw std::domain_error("unable to form triangle using these sides");
	}

	m_sides[0] = side1;
	m_sides[1] = side2;
	m_sides[2] = side3;

	m_perimeter = side1 + side2 + side3;
	double half_perimeter = m_perimeter / 2;
	m_area = sqrt(half_perimeter * (half_perimeter - side1) *
		(half_perimeter - side2) * (half_perimeter - side3));

}

double CTriangle::GetSide1() const
{
	return m_sides[0];
}

double CTriangle::GetSide2() const
{
	return m_sides[1];
}

double CTriangle::GetSide3() const
{
	return m_sides[2];
}

double CTriangle::GetArea() const
{
	return m_area;
}

double CTriangle::GetPerimeter() const
{
	return m_perimeter;
}
