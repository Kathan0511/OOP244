 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
    bool debug = false;
    int getTime()
    {
        int Minutes = -1;
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
                    Minutes = int(t);
                }
                cin.ignore(1000, '\n');
            } while (Minutes < 0);
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            Minutes = lt.tm_hour * 60 + lt.tm_min;
        }
        return Minutes;
    }

    int getInt()
    {
        int value;
        bool badEntry;
        char nextChar;
        do
        {
            badEntry = false;
            cin >> value;
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(3000, '\n');
                badEntry = true;
            }
            else
            {
                nextChar = cin.get();
                if (nextChar != '\n')
                {
                    cout << "Only enter an integer, try again: ";
                    cin.ignore(3000, '\n');
                    badEntry = true;
                }
            }
        } while (badEntry);
        return value;
    }
}