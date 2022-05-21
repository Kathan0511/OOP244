 
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds
{
	void Food::setName(const char* name)
	{
		strCpy(m_foodName, name);
		m_foodName[30] = '\0';
	}

	void Food::setEmpty()
	{
		m_foodName[0] = '\0';
		m_calNo = 0;
		m_consumeTime = 0;
	}

	void Food::set(const char* item_name, int calories, int when)
	{
		if (calories < 0 || item_name == nullptr)
		{
			setEmpty();
		}
		else
		{
			setName(item_name);
			m_calNo = calories;
			m_consumeTime = when;
		}
	}

	void Food::display() const
	{
		if (isValid())
		{
			cout << "| ";
			cout.width(30);
			cout << left << setfill('.') << m_foodName;
			cout << " | ";
			cout.width(4);
			cout << left << setfill(' ');
			cout << right << m_calNo;
			cout << " | ";
			cout.width(10);
			if (m_consumeTime == 1)
				cout << left << "Breakfast";
			else if (m_consumeTime == 2)
				cout << left << "Lunch";
			else if (m_consumeTime == 3)
				cout << left << "Dinner";
			else if (m_consumeTime == 4)
				cout << left << "Snack";
			cout << right << setfill(' ');
			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	bool Food::isValid() const
	{
		return m_foodName[0] != '\0' && m_consumeTime >= 1 && m_consumeTime <= 4;
	}

	int Food::calorie() const
	{
		return m_calNo;
	}
}