 

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    const char DATA_FILE[] = "employees.csv";
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* x) {





        if (fscanf(fptr, "%[^\n]\n", x) == 1)
        {

            return true;
        }
        else
        {
            return false;
        }



    }
    bool read(int& num) {



        if (fscanf(fptr, "%d,", &num) == 1)
        {


            return true;
        }
        else
        {

            return false;
        }


    }
    bool read(double& doubleNumber) {



        if (fscanf(fptr, "%lf,", &doubleNumber) == 1)
        {


            return true;
        }
        else
        {

            return false;
        }

    }

}