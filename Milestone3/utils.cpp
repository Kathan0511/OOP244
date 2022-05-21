 
//==============================================

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
    bool debug = true;  // made global in utils.h

    int getTime()
    {
        int mins = -1;
        if (debug)
        {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin)
                {
                    cout << "Invalid time, try agian (HH:MM): ";
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
        char nextCharac;

        if (debug)
        {
            if (prompt != nullptr)
                cout << prompt;
            do {
                cin.clear();
                cin >> value;

                if (!cin)
                {
                    cout << "Bad integer value, try again: ";
                    cin.clear();
                }
                else
                {
                    nextCharac = cin.get();
                    if (nextCharac == '\n')
                    {
                        return value;
                    }
                    else
                    {
                        cout << "Enter only an integer, try again: ";
                        value = 0;
                    }
                }
                cin.ignore(1000, '\n');
            } while (value == 0);
        }return value;
    }
    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
        int value = -1;
        char nextCharac;

        if (debug)
        {
            if (prompt != nullptr)
                cout << prompt;
            do {
                cin.clear();
                cin >> value;

                if (!cin)
                {
                    cout << "Bad integer value, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    value = -1;
                }
                else
                {
                    nextCharac = cin.get();

                    if (nextCharac == '\n')
                    {
                        if ((value < min) || (value > max))
                        {
                            value = -1;
                            if (errorMessage != nullptr)
                                cout << errorMessage;
                            /*else {
                                cout << "Enter only an integer, try again: ";
                            }*/
                            if (showRangeAtError)
                                cout << "[" << min << " <= value <= " << max << "]: ";
                        }
                    }
                    else
                    {
                        cout << "Enter only an integer, try again: ";
                        value = -1;
                    }
                }
            } while (value == -1);
        }return value;
    }
    char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
        bool valid = (prompt != nullptr);
        string value;
        if (valid)
        {
            cout << prompt;
        }
        getline(istr, value);

        char* str = new char[value.length() + 1];
        strcpy(str, value.c_str());

        return str;
    }
    void getcstrTester()
    {
        char* cstr;
        cout << "Copy and past the following at the prompt:" << endl;
        cout << "If you didn't care what happened to me, "
            "And I didn't care for you, "
            "We would zig zag our way through the boredom and pain, "
            "Occasionally glancing up through the rain. "
            "Wondering which of the brothers to blame. "
            "And watching for pigs on the wing." << endl;
        cstr = getcstr("Paste here /> ");
        cout << cstr << endl;
        delete[] cstr;
    }
}
