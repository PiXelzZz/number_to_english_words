// ConsoleApplication22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


//writing numbers from 1 to 19
string numbers(string number) {
	string words[20] = { "", "one ", "two ", "three ", "four ", "five ",
		"six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ",
		"thirteen ", "fourteen ", "fiveteen ", "sixteen ", "seventeen ", "eighteen " };

	int value = atoi(number.c_str());

	return words[value];

}

//writing 'ties
string tens(string number) {
	string words[8] = { "twenty ", "thirty ", "forty ", "fifty ", "sixty ",
		"seventy ", "eighty ", "ninety " };

	int value = atoi(number.c_str());

	return words[value - 2];
}

//writing thousands, milions, etc
string thousand(int place) {
	string operators[4] = { "hundred ", "thousand ", "milion ", "bilion " };

	string which_one;

	switch (place) {
	case 3:
	case 6:
	case 9:
		which_one = operators[0];
		break;
	case 4:
		which_one = operators[1];
		break;
	case 7:
		which_one = operators[2];
		break;
	case 10:
		which_one = operators[3];
		break;
	};

	return which_one;
}


int main()
{
	//input
	string number;
	cout << "Write any number: ";
	cin >> number;

	// if empty input
	if (number.empty())
		throw domain_error("You have not entered a valid number!");

	const int length = number.size();

	string text;

	//loop that makes the program work
	for (int position = 0, decimal = length;
		position < length;
		++position, --decimal) {
		//converting from char to string - easier to manipulate
		string digits(1, number[position]);

		//checking if the decimal is a one in which teens or ten's can occure
		if ((decimal - 1) % 3 == 1) {
			// is teens? if y - make proper operations to send the while "teens" update position & decimal
			if (digits == "1") {
				digits += number[position + 1];
				text = numbers(digits);
				++position;
				--decimal;
			}
			// skipping zero
			else if (digits == "0") {}
			//the rest are tens
			else {
				text = tens(digits);
			}
		}
		//if not teens or tens just write a number
		else {
			text = numbers(digits);
		}
		// couting the whole thing and checking if there is a thousand/milion operator needed
		cout << text << thousand(decimal);
	}
	cout << endl;

	return 0;
}


