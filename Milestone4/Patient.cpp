 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "Ticket.h"
#include "utils.h"
#define MAXLEN 50
using namespace std;
namespace sdds
{
	
	Patient::Patient(int ticketNum, bool IOflag)
	{
		patient_ticket = new Ticket(ticketNum);
		patient_IOflag = IOflag;
		patient_name = nullptr;
		patient_OHIP = 0;
	}
	Patient::~Patient()
	{
		delete[] patient_name;
		patient_name = nullptr;
		delete patient_ticket;
		patient_ticket = nullptr;
	}
	bool Patient::fileIO() const
	{
		return patient_IOflag;
	}
	void Patient::fileIO(bool IOflag)
	{
		patient_IOflag = IOflag;
	}
	bool Patient::operator==(const char t) const
	{
		return this->type() == t;
	}
	bool Patient::operator==(const Patient& p) const
	{
		return this->type() == p.type();
	}
	void Patient::setArrivalTime()
	{
		patient_ticket->resetTime();
	}
	Patient::operator Time() const
	{
		return patient_ticket->operator sdds::Time();
	}
	int Patient::number() const
	{
		return patient_ticket->number();
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << this->type() << "," << patient_name << "," << patient_OHIP << ",";
		patient_ticket->csvWrite(ostr);
		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr)
	{
		char name[MAXLEN + 1] = { '\0' };
		int OHIP = 0;
		delete[] patient_name;
		patient_name = nullptr;
		istr.getline(name, MAXLEN + 1, ',');
		if (strlen(name) == MAXLEN)
		{
			patient_name = new char[MAXLEN + 1];
			strncpy(patient_name, name, MAXLEN + 1);
			patient_name[MAXLEN] = '\0';
			istr.clear();
			istr.ignore(2000, ',');
		}
		else
		{
			patient_name = new char[strlen(name) + 1];
			strncpy(patient_name, name, strlen(name) + 1);
		}
		istr >> OHIP;
		if (OHIP >= 100000000 && OHIP <= 999999999)
		{
			patient_OHIP = OHIP;
		}
		istr.clear();
		istr.ignore(2000, ',');
		patient_ticket->csvRead(istr);
		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr) const
	{
		return patient_ticket->write(ostr) << endl << patient_name << ", OHIP: " << patient_OHIP;
	}
	std::istream& Patient::read(std::istream& istr)
	{
		char name[MAXLEN + 1] = { '\0' };
		int OHIP = 0;
		delete[] patient_name;
		cout << "Name: ";
		istr.get(name, MAXLEN + 1, '\n');
		istr.clear();
		istr.ignore(2000, '\n');
		patient_name = new char[strlen(name) + 1];
		strcpy(patient_name, name);
		cout << "OHIP: ";
		OHIP = getInt();
		while (OHIP < 100000000 || OHIP > 999999999)
		{
			cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
			OHIP = getInt();
		}
		patient_OHIP = OHIP;
		return istr;
	}
}