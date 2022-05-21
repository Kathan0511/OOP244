 


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;

namespace sdds
{
	bool debug = false;  // made global in utils.h
	int getTime()
	{
		int mins = -1;
		if (debug)
		{
			Time t(0);
			cout << "Enter current time: ";
			do
			{
				cin.clear();
				cin >> t;
				if (!cin)
				{
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				}
				else
				{
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else
		{
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}

	int getInt(const char* prompt)
	{
		int value = 0;
		int wrong = 1;

		if (prompt)
		{
			cout << prompt;
		}
		do
		{
			cin >> value;

			if (cin.fail())//checks for invalid character//value is not an int
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
			}
			else if (char(cin.get()) != '\n')
			{
				cout << "Enter only an integer, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
			}
			else
			{
				wrong = 0;
			}

		} while (wrong);

		return value;
	}

	int getInt(int minimum, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{

		int value = 0;
		int wrong = 1;

		if (prompt)
		{
			cout << prompt;
		}
		do
		{
			value = getInt();

			if (value <= max && value >= minimum)
			{
				wrong = 0;
			}

			if (wrong)
			{
				if (errorMessage)
				{
					cout << errorMessage;
				}

				if (showRangeAtError)
				{
					cout << "[" << minimum << " <= value <= " << max << "]: ";
				}

			}
		} while (wrong);

		return value;
	}

	char* getcstr(const char* prompt, std::istream& istring, char delimiter)
	{
		char* answer = nullptr;

		if (prompt)
		{
			cout << prompt;
		}

		string line;
		getline(istring, line);

		unsigned len = strlen(line.c_str());

		answer = new char[len + 1];
		strcpy(answer, line.c_str());

		return answer;
	}
}