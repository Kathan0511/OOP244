 

#include<iostream>
#include"cstring.h"

using namespace std;

namespace sdds {
    int strLen(const char* s)
    {
        int length = 0;
        for (; s[length] != '\0'; length++)
        {
        }
        return length;
    }

    void strCpy(char* des, const char* src)
    {

        while (*src != 0)
        {
            *des++ = *src++;
        }

        *des = '\0';
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        int length = strLen(src);
        for (; i < len && length; i++)
        {
            des[i] = src[i];
        }
        if (length < len)
        {
            des[i] = '\0';
        }
    }
    /* int strCmp(const char* s1, const char* s2) //// returns 0 i thare the same
    // return > 0 if s1 > s2
      // return < 0 if s1 < s2
     {
         int i = 0;
         int l1 = strLen(s1);
         int l2 = strLen(s2);
         while (s1[i] != '\0' && s2[i] != '\0')
         {

             if (s1[i] > s2[i])  return 1;
             else if (s1[i] < s2[i]) return -1;
             i++;
         }
         if (l1 == l2) return 0;
         else
         {
             if (l1 > l2)
                 return 1;
             else
                 return -1;
         }

     }*/

    int strCmp(const char* s1, const char* s2)

    {
        int i = 0;
        int i1 = strLen(s1);
        int i2 = strLen(s2);
        int flag = 1;
        while (s1[i] != '\0' && s2[i] != '\0')
        {

            if (s1[i] > s2[i])
            {
                flag = 1;
                //cout << flag;
            }
            else if (s1[i] < s2[i])
            {
                flag = -1;
                // cout << flag;
            };
            i++;
        }
        return flag;
        if (i1 == i2)
        {
            flag = 0;
            cout << flag;
        }
        else
        {
            if (i1 > i2)
            {

                flag = 1;
                cout << flag;
            }

            else
            {
                flag = -1;
                cout << flag;
            }

        }

    }
    /*int strnCmp(const char* s1, const char* s2, int length) // returns the lenght of the C-string in characters

    {
        int i = 0;

        while (i < length && s1[i] != '\0' && s2[i] != '\0')
        {

            if (s1[i] > s2[i])  return 1;
            else if (s1[i] < s2[i]) return -1;
            i++;
        }
        return 0;
    }*/

    int strnCmp(const char* s1, const char* s2, int length)

    {
        int flag = 0;
        int i = 0;

        while (i < length && s1[i] != '\0' && s2[i] != '\0')
        {

            if (s1[i] > s2[i])
            {
                //cout << flag;
                flag = 1;
            }
            else if (s1[i] < s2[i])
            {
                flag = -1;
                //  cout << flag;
            }
            i++;
        }
        return flag;
    }


    const char* strStr(const char* str1, const char* str2)

    {
        const char* ans;
        const char* a;
        ans = str2;

        if (str2 == 0)
            return str1;

        for (; *str1 != 0; str1++)
        {
            if (*str1 == *str2)
            {
                a = str1;
                while (*ans++ == *a++)
                {
                    if (*ans == 0)
                        return str1;
                    // if (*ans++ != *a++)  break;
                }
                ans = str2;

            }
        }
        return NULL;
    }
    /*
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
   */
    void strCat(char* des, const char* src)
    {
        int a = strLen(des);

        for (int i = 0; src[i] != '\0'; i++, a++)
        {
            des[a] = src[i];
        }
        des[a] = '\0';

    }
}

