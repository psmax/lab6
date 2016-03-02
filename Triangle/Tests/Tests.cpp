
#include "stdafx.h"
#include "../Triangle/Triangle.h"

BOOST_AUTO_TEST_SUITE(MyString)

BOOST_AUTO_TEST_CASE(NegativeSide)
{
	BOOST_CHECK_THROW(CTriangle(-2, 2, 3), std::invalid_argument);
	BOOST_CHECK_THROW(CTriangle(3, -2, 3), std::invalid_argument);
	BOOST_CHECK_THROW(CTriangle(3, 3, -3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidSideLength)
{
	BOOST_CHECK_THROW(CTriangle(2, 2, 8), std::domain_error);
	BOOST_CHECK_THROW(CTriangle(7, 2, 3), std::domain_error);
	BOOST_CHECK_THROW(CTriangle(1, 4, 1), std::domain_error);
}

BOOST_AUTO_TEST_CASE(CorrectTriangle)
{
	{
		CTriangle t(2, 2, 2);

		BOOST_CHECK_EQUAL(t.GetArea(), sqrt(3));
		BOOST_CHECK_EQUAL(t.GetPerimeter(), 6);
		BOOST_CHECK_EQUAL(t.GetSide1(), 2);
		BOOST_CHECK_EQUAL(t.GetSide2(), 2);
		BOOST_CHECK_EQUAL(t.GetSide3(), 2);
	}
	{
		CTriangle t(3.5, 4, 3);

		BOOST_CHECK_CLOSE_FRACTION(t.GetArea(), 5.083291, 1e-6);
		BOOST_CHECK_CLOSE(t.GetPerimeter(), 10.5, DBL_EPSILON);
		BOOST_CHECK_EQUAL(t.GetSide1(), 3.5);
		BOOST_CHECK_EQUAL(t.GetSide2(), 4);
		BOOST_CHECK_EQUAL(t.GetSide3(), 3);
	}
}

BOOST_AUTO_TEST_SUITE_END()
