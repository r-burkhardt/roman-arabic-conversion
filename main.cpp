/**********************************************************************\
	
	 * Roderick Burkhardt
	 * 2015/04/12
	 * 
	 * Program Name:	Roman / Arabic Numeral Conversion
	 
\**********************************************************************/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// function prototypes
int convertRomanNumerals(string);
bool validateRomanNumerals(string);
string capRomanNumerals(string);
string convertArabicNumerals(int);

int main()
{
	// variables
	char selection;
	string romanNum;
	bool validRomanNum;
	int arabicNum;
	
	// program loop that runs until user chooses to quit
	do
	{
		// program menu
		cout << "Roman Numeral/Arabic Numeral Conversion\n";
		cout << "=======================================\n";
		cout << "a ) Convert Roman Numerals to Arabic\n";
		cout << "r ) Convert Arabic Numerals to Roman\n";
		cout << "q ) Quit\n\n";
		
		cin >> selection;
		
		// processes the user's selection
		switch (selection)
		{
			case 'a':
				// selection to convert roman numerals to arabic numerals
				// queries user for roman numerals
				cout << "Enter a Roman Numeral string: ";
				
				cin >> romanNum;
	
				// converts any lowercase roman numerals to uppercase
				romanNum = capRomanNumerals(romanNum);
	
				// sends string to valid to ensure vaild roman numerals
				validRomanNum = validateRomanNumerals(romanNum);
	
				// loops until user inputs valid roman numerals
				while (validRomanNum != false)
				{
					cout << "\n Invalid Roman Numeral!\n";
					cout << "PLease Try again, using only I, V, X, L, C, D, or M : ";
		
					cin >> romanNum;
	
					// converts any lowercase roman numerals to uppercase
					romanNum = capRomanNumerals(romanNum);
		
					// sends string to valid to ensure vaild roman numerals
					validRomanNum = validateRomanNumerals(romanNum);
				}
			
				// converts roman numerals to arabic numerals
				arabicNum = convertRomanNumerals(romanNum);
	
				// displays the user inputed roman numeral and its arabic equivalant
				cout << "\n\nRoman Numeral \"" << romanNum << "\" converts to Arabic Numeral \"" << arabicNum << "\".\n\n";
				break;
				
			case 'r':
				// selection to convert arabic numerals to roman numerals
				// resets arabicNum variable to zero
				arabicNum = 0;
				
				// loops request for input until a valid input in received
				do
				{
					// queries the user for a number in arabic numerals between 0 and 4000
					cout << "Please enter a number between 0 and 4000: ";
				
					cin >> arabicNum;
					
					// tests for valid arabic numeral input by user
					if (cin.fail()) // test if cin fails cause input is not an integar
					{
						cout << "Invalid choice! \n";
						cin.clear();
						cin.ignore(256,'\n');
					}
					else if (arabicNum <= 0 || arabicNum >= 4000) // makes sure the input is between 0 and 4000
					{
						cout << "Invalid choice! \n";
					}
					
				} while (arabicNum <= 0 || arabicNum >= 4000);
				
				// send arabicNum to for coversion to the convertArabicNumerals function
				romanNum = convertArabicNumerals(arabicNum);
		
				// displays the user's arabic numeral input and the converted roman numeral outpout
				cout << "\n\nArabic Numeral \"" << arabicNum << "\" coverts to Roman Numeral \"" << romanNum << "\".\n\n";
				break;
				
			case 'q':
				// displays quit message and thank you for using
				cout << "You have choosen to quit.\n";
				cout << "Thank you for using Roman Numeral Converter\n";
				break;
				
			default:
				// displays invalid selection message and try again prompt
				cout << "Invalid selection! Please try again using only \"c\" or \"q\".\n";
		}
	} while (selection != 'q');
	
	return 0;
}

// function for coverting lowercase to uppercase
string capRomanNumerals(string inRomanNum)
{
	// local function variables
	string tempString;
	char inChar;
	
	//coverts and rebuilds string with uppercase characters
	for(int i = 0; i <= inRomanNum.length()-1; ++i)
	{
		inChar = toupper(inRomanNum[i]);
		tempString = tempString + inChar;
	}
	return tempString;
}

// function that checks for any invalid characters
bool validateRomanNumerals(string inRomanNum)
{
	// loops through string array checking for invalid characters
	for (int i = 0; i < inRomanNum.length(); ++i)
	{
		if ((inRomanNum[i] != 'I') && (inRomanNum[i] != 'V') && (inRomanNum[i] != 'X') && (inRomanNum[i] != 'L') && (inRomanNum[i] != 'C') && (inRomanNum[i] != 'D') && (inRomanNum[i] != 'M'))
		{
			// returns 1 if there is any non roman numeral characters in the string
			return "1";
		}
	}
	return 0;
}

// function converts roman numerals to its arabic equivant and adds them together
int convertRomanNumerals(string inRomanNum)
{
	// local function variable
	int romanCount = 0;
	
	// convert and add loop
	for(int i = inRomanNum.length()-1; i >= 0; --i)
	{
		if ((inRomanNum[i] == 'I') && (inRomanNum[i+1] == 'X'))
		{
			romanCount--;
		}
		else if ((inRomanNum[i] == 'I') && (inRomanNum[i+1] == 'V'))
		{
			romanCount--;
		}
		else if ((inRomanNum[i] == 'X') && (inRomanNum[i+1] == 'L'))
		{
			romanCount = romanCount - 10;
		}
		else if ((inRomanNum[i] == 'X') && (inRomanNum[i+1] == 'C'))
		{
			romanCount = romanCount - 10;
		}
		else if ((inRomanNum[i] == 'C') && (inRomanNum[i+1] == 'M'))
		{
			romanCount = romanCount - 100;
		}
		else if (inRomanNum[i] == 'I')
		{
			romanCount++;
		}
		else if (inRomanNum[i] == 'V')
		{
			romanCount = romanCount + 5;
		}
		else if (inRomanNum[i] == 'X')
		{
			romanCount = romanCount + 10;
		}
		else if (inRomanNum[i] == 'L')
		{
			romanCount = romanCount + 50;
		}
		else if (inRomanNum[i] == 'C')
		{
			romanCount = romanCount + 100;
		}
		else if (inRomanNum[i] == 'D')
		{
			romanCount = romanCount + 500;
		}
		else if (inRomanNum[i] == 'M')
		{
			romanCount = romanCount + 1000;
		}
	}
	
	// returns the arabic number to main
	return romanCount;
}


string convertArabicNumerals(int inArabicNum)
{
	// local variables
	string outRomanNum;
	
	// loops through the inArabicNum creating a roman numeral string to be sent back to main
	do
	{
		if (inArabicNum > 2999)
		{
			outRomanNum = outRomanNum + 'M';
			inArabicNum = inArabicNum - 1000;
		}
		else if (inArabicNum < 3000 && inArabicNum > 1999)
		{
			outRomanNum = outRomanNum + 'M';
			inArabicNum = inArabicNum - 1000;
		}
		else if (inArabicNum < 2000 && inArabicNum > 999)
		{
			outRomanNum = outRomanNum + 'M';
			inArabicNum = inArabicNum - 1000;
		}
		else if (inArabicNum < 1000 && inArabicNum > 899)
		{
			outRomanNum = outRomanNum + "CM";
			inArabicNum = inArabicNum - 900;
		}
		else if (inArabicNum < 900 && inArabicNum > 799)
		{
			outRomanNum = outRomanNum + "DCCC";
			inArabicNum = inArabicNum - 800;
		}
		else if (inArabicNum < 800 && inArabicNum > 699)
		{
			outRomanNum = outRomanNum + "DCC";
			inArabicNum = inArabicNum - 700;
		}
		else if (inArabicNum < 700 && inArabicNum > 599)
		{
			outRomanNum = outRomanNum + "DC";
			inArabicNum = inArabicNum - 600;
		}
		else if (inArabicNum < 600 && inArabicNum > 499)
		{
			outRomanNum = outRomanNum + 'D';
			inArabicNum = inArabicNum - 500;
		}
		else if (inArabicNum < 500 && inArabicNum > 399)
		{
			outRomanNum = outRomanNum + "CD";
			inArabicNum = inArabicNum - 400;
		}
		else if (inArabicNum < 400 && inArabicNum > 299)
		{
			outRomanNum = outRomanNum + "CCC";
			inArabicNum = inArabicNum - 300;
		}
		else if (inArabicNum < 300 && inArabicNum > 199)
		{
			outRomanNum = outRomanNum + "CC";
			inArabicNum = inArabicNum - 200;
		}
		else if (inArabicNum < 200 && inArabicNum > 99)
		{
			outRomanNum = outRomanNum + 'C';
			inArabicNum = inArabicNum - 100;
		}
		else if (inArabicNum < 100 && inArabicNum > 89)
		{
			outRomanNum = outRomanNum + "XC";
			inArabicNum = inArabicNum - 90;
		}
		else if (inArabicNum < 90 && inArabicNum > 79)
		{
			outRomanNum = outRomanNum + "LXXX";
			inArabicNum = inArabicNum - 80;
		}
		else if (inArabicNum < 80 && inArabicNum > 69)
		{
			outRomanNum = outRomanNum + "LXX";
			inArabicNum = inArabicNum - 70;
		}
		else if (inArabicNum < 70 && inArabicNum > 59)
		{
			outRomanNum = outRomanNum + "LX";
			inArabicNum = inArabicNum - 60;
		}
		else if (inArabicNum < 60 && inArabicNum > 49)
		{
			outRomanNum = outRomanNum + 'L';
			inArabicNum = inArabicNum - 50;
		}
		else if (inArabicNum < 50 && inArabicNum > 39)
		{
			outRomanNum = outRomanNum + "XL";
			inArabicNum = inArabicNum - 40;
		}
		else if (inArabicNum < 40 && inArabicNum > 29)
		{
			outRomanNum = outRomanNum + "XXX";
			inArabicNum = inArabicNum - 30;
		}
		else if (inArabicNum < 30 && inArabicNum > 19)
		{
			outRomanNum = outRomanNum + "XX";
			inArabicNum = inArabicNum - 20;
		}
		else if (inArabicNum < 20 && inArabicNum > 9)
		{
			outRomanNum = outRomanNum + 'X';
			inArabicNum = inArabicNum - 10;
		}
		else if (inArabicNum == 9)
		{
			outRomanNum = outRomanNum + "IX";
			inArabicNum = inArabicNum - 9;
		}
		else if (inArabicNum == 8)
		{
			outRomanNum = outRomanNum + "VIII";
			inArabicNum = inArabicNum - 8;
		}
		else if (inArabicNum == 7)
		{
			outRomanNum = outRomanNum + "VII";
			inArabicNum = inArabicNum - 7;
		}
		else if (inArabicNum == 6)
		{
			outRomanNum = outRomanNum + "VI";
			inArabicNum = inArabicNum - 6;
		}
		else if (inArabicNum == 5)
		{
			outRomanNum = outRomanNum + 'V';
			inArabicNum = inArabicNum - 7;
		}
		else if (inArabicNum == 4)
		{
			outRomanNum = outRomanNum + "IV";
			inArabicNum = inArabicNum - 4;
		}
		else if (inArabicNum == 3)
		{
			outRomanNum = outRomanNum + "III";
			inArabicNum = inArabicNum - 3;
		}
		else if (inArabicNum == 2)
		{
			outRomanNum = outRomanNum + "II";
			inArabicNum = inArabicNum - 2;
		}
		else if (inArabicNum == 1)
		{
			outRomanNum = outRomanNum + 'I';
			inArabicNum = inArabicNum - 1;
		}
	} while (inArabicNum != 0);
		
	// returns the roman numeral string to main
	return outRomanNum;

}