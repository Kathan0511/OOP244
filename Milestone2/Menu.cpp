 


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;

namespace sdds
{
	void Menu::display() const
	{
		cout << m_txt;
		cout << endl << "0- Exit" << endl;
	}

	Menu::Menu(const char* MenuContent, int nOfSelect)
	{
		m_noOfSel = nOfSelect;
		m_txt = nullptr;
		if (MenuContent)
		{
			m_txt = new char[strlen(MenuContent) + 1];
			strcpy(m_txt, MenuContent);
		}
	}

	Menu::~Menu()
	{
		delete[] m_txt;
		m_txt = nullptr;
	}

	int& Menu::operator>>(int& select)
	{
		display();
		select = getInt(0, m_noOfSel, "> ", "Invalid option ");
		return select;
	}

	Menu::Menu(const Menu& rhtOperator)
	{
		m_txt = nullptr;
		m_noOfSel = rhtOperator.m_noOfSel;

		if (rhtOperator.m_txt)
		{
			m_txt = new char[strlen(rhtOperator.m_txt) + 1];
			strcpy(m_txt, rhtOperator.m_txt);
		}
	}
}
