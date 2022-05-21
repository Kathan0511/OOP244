 
#include "cstring.h"
#include <iostream>

namespace sdds {
    int strLen(const char* s)
    {
        int length = 0;
        for (; s[length] != '\0'; length++)
        {
        }
        return length;
    }

    void strCpy(char* des, const char* src)  //Copies the source character string into the destination
    {

        while (*src != 0)
        {
            *des++ = *src++;
        }

        *des = '\0';
    }

    void strnCpy(char* des, const char* src, int len) //Compares two C Strings
    {
        int a = 0;
        int length = strLen(src);
        for (; a < len && length; a++)
        {
            des[a] = src[a];
        }
        if (length < len)
        {
            des[a] = '\0';
        }
    }

    int strCmp(const char* s1, const char* s2) //// returns 0 i thare the same
     // return > 0 if s1 > s2
     // return < 0 if s1 < s2
    {
        int a = 0;
        int a1 = strLen(s1);
        int a2 = strLen(s2);
        while (s1[a] != '\0' && s2[a] != '\0')
        {

            if (s1[a] > s2[a])  return 1;
            else if (s1[a] < s2[a]) return -1;
            a++;
        }
        if (a1 == a2) return 0;
        else
        {
            if (a1 > a2)
                return 1;
            else
                return -1;
        }

    }

    int strnCmp(const char* s1, const char* s2, int length) // returns the lenght of the C-string in characters

    {
        int i = 0;

        while (i < length && s1[i] != '\0' && s2[i] != '\0')
        {

            if (s1[i] > s2[i])  return 1;
            else if (s1[i] < s2[i]) return -1;
            i++;
        }
        return 0;
    }

    const char* strStr(const char* str1, const char* str2) // Concantinates "src" C-string to the end of "des"

    {
        const char* ans;
        const char* a;
        ans = str2;

        if (str2 == 0)
            return str1;

        for (; *str1 != 0; str1++)
        {
            if (*str1 != *str2)  continue;
            a = str1;
            for (;;)
            {
                if (*ans == 0) return str1;
                if (*ans++ != *a++)  break;
            }
            ans = str2;
        }
        return NULL;
    }

    void strCat(char* des, const char* src)
    {
        int a1 = strLen(des);

        for (int i = 0; src[i] != '\0'; i++, a1++)
        {
            des[a1] = src[i];
        }
        des[a1] = '\0';

    }
}

