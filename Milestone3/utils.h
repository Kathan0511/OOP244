 

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds
{
    extern bool debug; // making sdds::debug variable global to all the files
                       // which include: "utils.h"

    int getTime(); // returns the time of day in minutes
    int getInt(const char* prompt = nullptr);
    int getInt(int min, int max, const char* prompt = nullptr, const char* errorMessage = nullptr,
        bool showRangeAtError = true);
    char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');
}
#endif // !SDDS_UTILS_H_