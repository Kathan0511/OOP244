 

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds
{
	class CalorieList
	{
		Food* m_items;
		int m_noOfItems;
		int m_itemsAdded;
		int totalCalorie()const;
		void Title()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;
	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();
	};
}
#endif