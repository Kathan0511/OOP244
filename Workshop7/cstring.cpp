 

#include "cstring.h"
namespace sdds
{


	void strCpy(char* des, const char* src)
	{
		int i = 0;
		while (src[i] != '\0')
		{
			des[i] = src[i];
			i++;
		}

		if (src[i] == '\0')
		{
			des[i] = '\0';
		}

	}



	void strnCpy(char* des, const char* src, int len)
	{
		int i;

		for (i = 0; i < len; i++)
		{
			if (src[i] == '\0')
			{
				des[i] = '\0';
			}
			else
			{
				des[i] = src[i];
			}
		}
	}



	int strCmp(const char* s1, const char* s2)
	{
		int i = 0, cmpVar = 0;
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] == s2[i])
			{
				cmpVar = 0;
				i++;
			}
			else if (s1[i] > s2[i])
			{
				cmpVar = 1;
				break;
			}
			else
			{
				cmpVar = -1;
				break;
			}
		}

		return cmpVar;
	}



	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i = 0, cmpVar = 0;

		while (s1[i] != '\0' || s2[i] != '\0')
		{
			for (i = 0; i < len; i++)
			{
				if (s1[i] == s2[i])
				{
					cmpVar = 0;
				}
				else if (s1[i] > s2[i])
				{
					cmpVar = 1;
					break;
				}
				else
				{
					cmpVar = -1;
					break;
				}
			}
			break;
		}

		return cmpVar;
	}



	int strLen(const char* s)
	{
		int i = 0, len = 0;
		while (s[i] != '\0')
		{
			len++;
			i++;
		}

		return len;
	}


	const char* strStr(const char* str1, const char* str2)
	{
		int i;

		for (i = 0; i < strLen(str1); i++)
		{
			if (strnCmp(&str1[i], str2, strLen(str2)) == 0)
				return &str1[i];
		}

		return nullptr;
	}



	void strCat(char* des, const char* src)
	{
		int i = 0;
		int desStrnLen = strLen(des);

		while (src[i] != '\0')
		{
			des[desStrnLen] = src[i];
			desStrnLen++;
			i++;
		}
		if (src[i] == '\0')
			des[desStrnLen] = '\0';
	}
}


