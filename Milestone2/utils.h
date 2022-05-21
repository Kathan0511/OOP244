 


#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds
{
	extern bool debug; // making sdds::debug variable global to all the files
					   // which include: "utils.h"

	int getTime(); // returns the time of day in minutes

	int getInt
	(
		const char* prompt = nullptr   // User entry prompt
	);

	int getInt(
		int minimum,   // minimum acceptable value
		int max,   // max acceptable value
		const char* prompt = nullptr,  // get user data
		const char* errorMessage = nullptr, // error message
		bool showRangeAtError = true    // show error range
	);

	char* getcstr(
		const char* prompt = nullptr,   // get user data
		std::istream& istring = std::cin,  // reading from the Stream
		char delimiter = '\n'    // Delimiter marks the end of data
	);

}
#endif // !SDDS_UTILS_H_