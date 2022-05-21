 

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "TriagePatient.h"
#define MAXCHARS 511

using namespace std;
namespace sdds {
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		symptoms = nullptr;
		nextTriageTicket++;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	TriagePatient::~TriagePatient()
	{
		delete[] symptoms;
		symptoms = nullptr;
	}

	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr) << ',' << symptoms;
		return ostr;
	}

	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		char cstr_symptoms[MAXCHARS + 1] = { '\0' };
		delete[] symptoms;
		Patient::csvRead(istr);
		istr.ignore(2000, ',');
		istr.get(cstr_symptoms, MAXCHARS + 1, '\n');
		symptoms = new char[strlen(cstr_symptoms) + 1];
		strncpy(symptoms, cstr_symptoms, strlen(cstr_symptoms) + 1);
		istr.clear();
		nextTriageTicket = Patient::number() + 1;
		return istr;
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (Patient::fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr) << endl;
			ostr << "Symptoms: " << symptoms << endl;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		char cstr_symptoms[MAXCHARS + 1] = { '\0' };
		if (Patient::fileIO())
		{
			csvRead(istr);
		}
		else
		{
			delete[] symptoms;
			Patient::read(istr);
			cout << "Symptoms: ";
			istr.get(cstr_symptoms, MAXCHARS + 1, '\n');
			istr.clear();
			istr.ignore(2000, '\n');
			symptoms = new char[strlen(cstr_symptoms) + 1];
			strcpy(symptoms, cstr_symptoms);
		}
		return istr;
	}


}