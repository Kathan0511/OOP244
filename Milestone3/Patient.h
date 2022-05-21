 

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace sdds
{
	class Patient : public IOAble
	{
		char* m_patientName = nullptr;
		int m_ohip = 0;
		Ticket m_ticket = 0;
		bool m_flagFile = false;
	public:
		Patient(int ticket, bool flag);
		~Patient();
		virtual char type()const;
		bool fileIO()const;
		void fileIO(bool value);
		bool operator==(char character)const;
		bool operator==(const Patient& p1)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);


	};
}
#endif // !SDDS_PATIENT_H_