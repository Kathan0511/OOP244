 

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds
{

	class Menu
	{
		char* m_txt; // holds the menu content dynamically
		int m_noOfSel;  // holds the number of options displayed in menu content
		void display()const;
	public:
		Menu(const char* MenuContent, int nOfSelect);
		virtual ~Menu();
		int& operator>>(int& select);
		// add safe copying logic
		Menu(const Menu& rhtOperator);
		Menu& operator=(const Menu& rhtOperator) = delete;
	};
}
#endif // !SDDS_MENU_H