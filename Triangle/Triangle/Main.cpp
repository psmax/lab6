// Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Triangle.h"
#include <string>

using namespace std;

bool InputDouble(const char *prompt, double &res)
{
	try
	{
		string userInput;
		cout << prompt;
		getline(cin, userInput);

		if (userInput.length() == 0)
		{
			return false;
		}

		res = stod(userInput);
	}
	catch (const invalid_argument &ex)
	{
		ex;
		throw invalid_argument("entered value is not a number");
	}
	catch (const out_of_range &ex)
	{
		ex;
		throw invalid_argument("entered value is out of range");
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	do
	{
		try
		{
			double side[3];

			cout << "Enter triangle sides (or empty line to exit)" << endl;
			if (!InputDouble("First side : ", side[0]) ||
				!InputDouble("Second side : ", side[1]) ||
				!InputDouble("Third side : ", side[2]))
			{
				break;
			}

			CTriangle triangle(side[0], side[1], side[2]);

			cout << "Area: " << triangle.GetArea() << endl;
			cout << "Perimeter: " << triangle.GetPerimeter() << endl;
		}
		catch (const logic_error &ex)
		{
			cout << "Cannot create triangle: " << ex.what() << endl;
		}
	} while (!cin.eof());

	return 0;
}
