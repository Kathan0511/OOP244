 

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds
{
	class Patient :public IOAble {
		char* patient_name;
		int patient_OHIP;
		Ticket* patient_ticket;
		bool patient_IOflag;
	public:
	
		Patient(int ticketNum = 0, bool IOflag = false);
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		~Patient();
		virtual char type()const = 0;		
		bool fileIO()const;
		void fileIO(bool IOflag);
		bool operator==(const char t)const;
		bool operator==(const Patient&)const;
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