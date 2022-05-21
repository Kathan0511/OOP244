 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invalid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt(const char* prompt)
    {
        // 0 for invalid integer, 1 for valid integer and other character, 2 for valid
        int flag = 0;
        bool int_encountered = false;
        int num;
        if (prompt != nullptr)
            cout << prompt;
        string line;
        getline(cin, line);
        line = line + '\n';

        while (flag != 2)
        {
            num = 0;
            int i = 0;
            while (line[i])
            {
                if (!isdigit(line[i]))
                {
                    if (!int_encountered)
                        flag = 0;
                    else if (line[i] == '\n')
                        flag = 2;
                    else
                        flag = 1;
                    break;
                }
                else
                {
                    int_encountered = true;
                    num = num * 10 + line[i] - '0';
                }
                i++;
            }
            if (flag != 2)
            {
                if (flag == 0)
                    cout << "Bad integer value, try again: ";
                else
                    cout << "Enter only an integer, try again: ";
                getline(cin, line);
                line = line + '\n';
            }
        }
        return num;
    }

    int getInt(
        int min,   // minimum acceptable value
        int max,   // maximum acceptable value
        const char* prompt,  // User entry prompt
        const char* errorMessage, // Invalid value error message
        bool showRangeAtError     // display the range if invalud value entered 
    )
    {
        // 0 for invalid integer, 1 for valid integer and other character, 2 for valid
        int flag = 0;
        bool int_encountered = false;
        int num;
        if (prompt != nullptr)
            cout << prompt;
        string line;
        getline(cin, line);
        line = line + '\n';

        while (flag != 2)
        {
            num = 0;
            int i = 0;
            while (line[i])
            {
                if (!isdigit(line[i]))
                {
                    if (!int_encountered)
                        flag = 0;
                    else if (line[i] == '\n')
                        flag = 2;
                    else
                        flag = 1;
                    break;
                }
                else
                {
                    int_encountered = true;
                    num = num * 10 + line[i] - '0';
                }
                i++;
            }
            if (flag != 2)
            {
                if (flag == 0)
                    cout << "Bad integer value, try again: ";
                else
                    cout << "Enter only an integer, try again: ";
                getline(cin, line);
                line = line + '\n';
            }
            else if (num < min || num > max)
            {
                flag = 0;
                if (errorMessage != nullptr)
                    cout << errorMessage;
                if (showRangeAtError)
                {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }
                getline(cin, line);
                line = line + '\n';
            }
        }
        return num;
    }

    char* getcstr(
        const char* prompt,   // User entry prompt
        std::istream& istr,  // the Stream to read from
        char delimiter     // Delimiter to mark the end of data
    )
    {
        if (prompt != nullptr)
            cout << prompt;
        string inp_string;
        getline(istr, inp_string);
        int len = inp_string.length();
        char* str = new char[len + 1];
        strcpy(str, inp_string.c_str());
        str[len] = '\0';
        return str;
    }
}