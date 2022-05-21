 

#include <iostream>
using namespace std;
#include "Truck.h"

namespace sdds
{
	Truck::Truck(const char* plateNum, int year, double capacity, const char* currentAddress) : MotorVehicle(plateNum, year, currentAddress)
	{
		m_volume = 0.000000000;
		m_capacity = capacity;
	}
	bool Truck::addCargo(double cargo)
	{
		bool ret = true;
		if (m_volume == m_capacity)
			ret = false;
		else if ((m_volume + cargo) >= m_capacity)
			m_volume = m_capacity;
		else
			m_volume += cargo;
		return ret;
	}
	bool Truck::unloadCargo()
	{
		bool ret = true;
		if (m_volume != 0)
			m_volume = 0;
		else
			ret = false;
		return ret;
	}
	std::ostream& Truck::write(std::ostream& os) const
	{
		MotorVehicle::write(os);
		os << " | " << m_volume << "/" << m_capacity;
		return os;
	}
	std::istream& Truck::read(std::istream& is)
	{
		MotorVehicle::read(is);
		double capacity, volume;
		cout << "Capacity: ";
		is >> capacity;
		cout << "Cargo: ";
		is >> volume;
		m_volume = volume;
		m_capacity = capacity;
		return is;
	}
	istream& operator>>(istream& left, Truck& obj)
	{
		return obj.read(left);
	}
	ostream& operator<<(ostream& left, const Truck& obj)
	{
		return obj.write(left);
	}
}