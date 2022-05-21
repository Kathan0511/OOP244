 

namespace sdds
{
	//----------------------------------------strCpy()-------------------------------------
	void strCpy(char* des, const char* src)
	{

		for (int i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
			des[i + 1] = '\0';
		}


	}
	//---------------------------------------strnCpy()------------------------------------------
	void strnCpy(char* des, const char* src, int len)
	{
		int counter = 0;
		bool status;
		for (int i = 0; src[i] != '\0'; i++)
		{
			counter++;
		}
		status = (counter < len) ? true : false;
		switch (status)
		{
		case true:
		{
			strCpy(des, src);
			break;
		}
		case false:
		{
			for (int i = 0; i < len; i++)
			{
				des[i] = src[i];
			}
			break;
		}
		}


	}
	//--------------------------------------------------strCmp()--------------------------------
	int strCmp(const char* s1, const char* s2)
	{
		int pos, s1Length = 0, s2Length = 0;
		bool status = true;
		for (int i = 0; s1[i] != '\0'; i++)
			s1Length++;
		for (int i = 0; s2[i] != '\0'; i++)
			s2Length++;
		if (s1Length != s2Length)
			status = false;
		for (int i = 0; i < s1Length && status; i++)
		{
			if (s1[i] != s2[i])
			{
				pos = i;
				status = false;
			}
		}
		switch (status)
		{
		case true:
		{
			return 0;
			break;
		}
		case false:
		{
			return (((int)s1[pos] > (int)s2[pos]) ? 1 : -1);
			break;
		}
		}

	}
	//-------------------------------------------------strnCmp()----------------------------------
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int pos;
		bool status = true;
		for (int i = 0; i < len && status; i++)
		{
			if (s1[i] != s2[i])
			{
				pos = i;
				status = false;
			}
		}
		switch (status)
		{
		case true:
		{
			return 0;
			break;
		}
		case false:
		{
			return (((int)s1[pos] > (int)s2[pos]) ? 1 : -1);
			break;
		}
		}
	}
	//-----------------------------------------------------strLen()-------------------------------
	int strLen(const char* s)
	{
		int counter = 0;
		for (int i = 0; s[i] != '\0'; i++)
		{
			counter++;
		}
		return counter;
	}
	//-------------------------------------------------------strStr()------------------------------------
	const char* strStr(const char* str1, const char* str2)
	{
		int counter;
		int str2Length = strLen(str2);
		int str1Length = strLen(str1);
		bool status;
		for (int i = 0; str1[i] != '\0'; i++)
		{

			if (str1[i] == str2[0] && (str1Length - i >= str2Length))
			{
				counter = 0;
				status = true;
				for (int j = i; j < i + str2Length && status; j++)
				{
					if (str1[j] != str2[counter])
					{
						status = false;
					}
					counter++;
				}
				if (status)
					return (str1 + i);
			}
		}
		return nullptr;
	}
	//----------------------------------------strCat()------------------------------------------
	void strCat(char* des, const char* src)
	{
		int desCounter = 0, srcCounter = 0;
		int srcLength = strLen(src);
		for (int i = 0; des[i] != '\0'; i++)
			desCounter++;
		for (int i = desCounter; i < desCounter + srcLength; i++)
		{
			des[i] = src[srcCounter];
			srcCounter++;
			des[i + 1] = '\0';
		}
	}
}