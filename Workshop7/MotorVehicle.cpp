 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "MotorVehicle.h"
using namespace std;
namespace sdds
{
	void MotorVehicle::setNumberPlate(const char* platenum)
	{
		int len = strlen(platenum) > 8 ? 8 : strlen(platenum);
		strncpy(m_plateNum, platenum, len);
		m_plateNum[len] = '\0';
	}
	void MotorVehicle::setAddress(const char* address)
	{
		int len = strlen(address) > 63 ? 63 : strlen(address);
		strncpy(m_address, address, len);
		m_address[len] = '\0';
	}
	MotorVehicle::MotorVehicle(const char* plateNum, int year, const char* address)
	{
		strncpy(m_plateNum, plateNum, 8);
		m_plateNum[8] = '\0';
		if (strcmp(address, "Factory") != 0)
		{
			strcpy(m_address, "Factory");
			moveTo(address);
		}
		setAddress(address);
		m_year = year;
	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (strcmp(m_address, address) != 0)
		{
			cout << "|" << setw(8) << right << m_plateNum << "| |";
			cout << setw(20) << right << m_address << " ---> ";
			setAddress(address);
			cout << setw(20) << left << address << "|" << endl;
			//cout << *this;
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		os << "| " << m_year << " | " << m_plateNum << " | " << m_address;
		return os;
	}
	std::istream& MotorVehicle::read(std::istream& is)
	{
		int year;
		string platenum, address;
		cout << "Built year: ";
		is >> year;
		cout << "License plate: ";
		is.ignore();
		getline(is, platenum);
		//address 64 chars
		cout << "Current location: ";
		getline(is, address);
		m_year = year;
		setNumberPlate(platenum.c_str());
		setAddress(address.c_str());
		return is;
	}
	std::istream& operator>>(std::istream& left, MotorVehicle& obj)
	{
		return obj.read(left);
	}
	std::ostream& operator<<(std::ostream& left, const MotorVehicle& obj)
	{
		return obj.write(left);
	}
}