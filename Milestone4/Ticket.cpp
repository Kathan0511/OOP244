 

#include "Ticket.h"
namespace sdds {
    Ticket::Ticket(int number) {
        Tic_number = number;
    }
    Ticket::operator Time() const {
        return Tic_time;
    }
    int Ticket::number() const {
        return Tic_number;
    }
    void Ticket::resetTime() {
        Tic_time.reset();
    }
    std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
        return ostr << Tic_number << "," << Tic_time;
    }
    std::istream& Ticket::csvRead(std::istream& istr) {
        istr >> Tic_number;
        istr.ignore();
        return istr >> Tic_time;
    }
    std::ostream& Ticket::write(std::ostream& ostr) const {
        return ostr << "Ticket No: " << Tic_number << ", Issued at: " << Tic_time;
    }
    std::istream& Ticket::read(std::istream& istr) {
        return csvRead(istr);
    }
}