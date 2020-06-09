// Assignment 2: main.cpp
// 
// This program converts Roman number system values into their equivalent Hindu-Arabic  number system values.   
// 
// Shane Calado, A00817064
// ver. 1.0
// Jan. 20th, 2018

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	int count = 1;
	int number = 0;

	const int MAX_CONVERSIONS = 10;

	char input;
	char previousInput;

	cout << MAX_CONVERSIONS  << " Roman numeral values will be input and converted into\n"
		<< "their equivalent Hindu-Arabic numeric values.\n" << endl;

	// Repeat conversion until the maximum allowable amount of times.
	while (count <= MAX_CONVERSIONS)
	{
		cout << "Input Roman numeral # " << count << ": ";
		previousInput = 'Z';

		// Repeat steps for each character in the user's input.
		while ((previousInput != 'N') && (input = cin.get()))
		{
			// Case for each roman numberal.
			switch (toupper(input))
			{
			case 'I':
				number += 1;
				// Checks to see if an error (invalid input) has occured.
				if (previousInput != 'E')
				{
					cout << "I";
					previousInput = 'I';
				}
				break;

			case 'V':
				number += 5;
				if (previousInput == 'I')
				{
					number -= 2;
				}
				if (previousInput != 'E')
				{
					cout << "V";
					previousInput = 'V';
				}
				break;

			case 'X':
				number += 10;
				if (previousInput == 'I')
				{
					number -= 2;
				}
				else if (previousInput == 'V')
				{
					number -= 10;
				}
				if (previousInput != 'E')
				{
					cout << "X";
					previousInput = 'X';
				}
				break;

			case 'L':
				number += 50;
				if (previousInput == 'I')
				{
					number -= 2;
				}
				else if (previousInput == 'V')
				{
					number -= 10;
				}
				else if (previousInput == 'X')
				{
					number -= 20;
				}
				if (previousInput != 'E')
				{
					cout << "L";
					previousInput = 'L';
				}
				break;

			case 'C':
				number += 100;
				if (previousInput == 'I')
				{
					number -= 2;
				}
				else if (previousInput == 'V')
				{
					number -= 10;
				}
				else if (previousInput == 'X')
				{
					number -= 20;
				}
				else if (previousInput == 'L')
				{
					number -= 100;
				}
				if (previousInput != 'E')
				{
					cout << "C";
					previousInput = 'C';
				}
				break;

			case 'D':
				number += 500;
				if (previousInput == 'I')
				{
					number -= 2;
				}
				else if (previousInput == 'V')
				{
					number -= 10;
				}
				else if (previousInput == 'X')
				{
					number -= 20;
				}
				else if (previousInput == 'L')
				{
					number -= 40;
				}
				else if (previousInput == 'C')
				{
					number -= 200;
				}
				if (previousInput != 'E')
				{
					cout << "D";
					previousInput = 'D';
				}
				break;

			case 'M':
				number += 1000;
				if (previousInput == 'I')
				{
					number -= 2;
				}
				else if (previousInput == 'V')
				{
					number -= 10;
				}
				else if (previousInput == 'X')
				{
					number -= 20;
				}
				else if (previousInput == 'L')
				{
					number -= 100;
				}
				else if (previousInput == 'C')
				{
					number -= 200;
				}
				else if (previousInput == 'D')
				{
					number -= 1000;
				}
				if (previousInput != 'E')
				{
					cout << "M";
					previousInput = 'M';
				}
				break;
				
			// Case for \n character to signal the end of the input.
			case '\n':
				if (previousInput != 'E')
				{
					cout << " = " << number;
				}
				cout << '\n' << endl;
				number = 0;
				count++;
				// Assign N to previousOutput to signal to go to the next line.
				previousInput = 'N';
				break;

			// Case to catch invalid input from the user.
			default:
				cout << input << " Error - last character was not valid!!!";
				number = 0;
				// Assign E to previousOutput to signal an error has occured.
				previousInput = 'E';
				break;

			}
		}
	}

	cout << "THAT'S ALL FOLKS :)\n" << endl;

	system("pause");
	return 0;
}