 

#define _CRT_SECURE_NO_WARNINGS

#include "IOAble.h"
#include "Ticket.h"
#include "utils.h"
#include "Patient.h"
#include <stdio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <ios>

using namespace std;

namespace sdds
{
	Patient::Patient(int ticket, bool flag) : m_ticket(ticket)
	{
		m_flagFile = flag;
	}
	Patient::~Patient()
	{
		delete[] m_patientName;
		m_patientName = nullptr;
	}
	char Patient::type()const
	{
		char value = { '\0' };
		return value;
	}
	bool Patient::fileIO()const
	{
		return m_flagFile;
	}
	void Patient::fileIO(bool value)
	{
		m_flagFile = value;
	}
	bool Patient::operator==(char character)const
	{
		bool valid = true;
		char typeValid = type();
		if (character != typeValid)
		{
			valid = false;
		}
		return valid;
	}
	bool Patient::operator==(const Patient& p)const
	{
		bool valid = true;
		if (p.type() != this->type())
		{
			valid = false;
		}
		return  valid;
	}
	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}
	int Patient::number()const
	{
		return m_ticket.number();
	}
	Patient::operator Time() const
	{
		return m_ticket;
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr)const
	{
		ostr << type() << ','
			<< m_patientName << ','
			<< m_ohip << ',';
		m_ticket.csvWrite(ostr);
		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr)
	{
		string name;
		getline(istr, name, ',');
		delete[] m_patientName;
		m_patientName = nullptr;
		m_patientName = new char[name.length() + 1];
		strcpy(m_patientName, name.c_str());

		istr >> m_ohip;
		istr.ignore(100, ',');

		m_ticket.csvRead(istr);

		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr)const
	{
		int lenName = 0;
		if (strlen(m_patientName) > 25)
			lenName = 25;
		else lenName = strlen(m_patientName);

		ostr << m_ticket
			<< endl;
		for (int i = 0; i < lenName; i++)
		{
			ostr << m_patientName[i];
		}
		ostr << ',' << " OHIP: "
			<< m_ohip;

		return ostr;

	}
	std::istream& Patient::read(std::istream& istr)
	{
		string patientnName;
		cout << "Name: ";
		getline(istr, patientnName, '\n');

		delete[] m_patientName;
		m_patientName = nullptr;
		m_patientName = new char[patientnName.length() + 1];
		strcpy(m_patientName, patientnName.c_str());

		cout << "OHIP:";
		m_ohip = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");

		return istr;
	}
}