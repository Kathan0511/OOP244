 

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds
{
	int CalorieList::totalCalorie() const
	{
		int total = 0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			total += m_items[i].calorie();
		}
		return total;
	}

	void CalorieList::Title() const
	{
		cout << "+----------------------------------------------------+" << endl;
		if (isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer() const
	{
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid())
		{
			cout << "|    Total Calories for today:";
			cout.width(9);
			cout << right << totalCalorie();
			cout << " | ";
			cout.width(12);
			cout << setfill(' ');
			cout << " |" << endl;
		}
		else
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::setEmpty()
	{
		m_items = nullptr;
	}

	bool CalorieList::isValid() const
	{
		bool valid = true;
		int i;
		valid = m_items != nullptr;
		for (i = 0; valid == true && i < m_noOfItems; i++)
		{
			valid = valid && m_items[i].isValid();
		}
		return valid;
	}

	void CalorieList::init(int size)
	{
		if (size < 1)
		{
			m_noOfItems = 0;
			m_itemsAdded = 0;
		}
		else
		{
			m_noOfItems = size;
			m_itemsAdded = 0;
			m_items = new Food[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++)
				m_items[i].setEmpty();
		}
	}

	bool CalorieList::add(const char* item_name, int calories, int when)
	{
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded++;
			return true;
		}
		return false;
	}

	void CalorieList::display() const
	{
		Title();
		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}
		footer();
	}

	void CalorieList::deallocate()
	{
		delete[] m_items;
	}
}