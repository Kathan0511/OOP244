 
#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>

namespace sdds
{
	class MotorVehicle
	{
		char m_plateNum[9];
		char m_address[64];
		int m_year;
		void setNumberPlate(const char* platenum);
		void setAddress(const char* address);
	public:
		MotorVehicle(const char* plateNum, int year, const char* address = "Factory");
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os /*= std::cout*/) const;
		std::istream& read(std::istream& in /*= std::cin*/);
	};
	std::istream& operator>>(std::istream& left, MotorVehicle& obj);
	std::ostream& operator<<(std::ostream& left, const MotorVehicle& obj);
}
#endif