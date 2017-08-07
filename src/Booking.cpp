#include <string>
#include <iostream>
#include <iomanip>

#include "Booking.h"
#include "FlightInfo.h"

/* ------------------------------------------------------------- */

Booking::Booking(long _bookingID, long _passengerID, PassengerFlightInfo _pfi, std::string& _seat, std::string& _priority):m_bookingID(_bookingID), m_passengerID(_passengerID), m_flightID(_pfi.m_flightID), m_flightTime(_pfi.m_flightTime), m_destination(_pfi.m_destination), m_departure(_pfi.m_departure), m_seatAssignment(_seat), m_priority(_priority), m_price(_pfi.m_price), m_date(_pfi.m_date)
{
  if (m_priority == "Priority")
  {
    m_price *= 1.5;
  }
};

/* ------------------------------------------------------------- */

Booking::Booking(const Booking& _ex):m_bookingID(_ex.m_bookingID), m_passengerID(_ex.m_passengerID), m_flightID(_ex.m_flightID), m_flightTime(_ex.m_flightTime), m_destination(_ex.m_destination), m_departure(_ex.m_departure), m_seatAssignment(_ex.m_seatAssignment), m_priority(_ex.m_priority), m_price(_ex.m_price), m_date(_ex.m_date)
{};

/* ------------------------------------------------------------- */

void Booking::printInfo() const
{
  std::cout << "      |˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚|" << std::endl;
  std::cout << "      |                 Ticket                |" << std::endl;
  std::cout << "      | Booking ID:                   " << std::setw(7) << getBookingID() << " |" << std::endl;
  std::cout << "      | Route:                    " << std::setw(4) << getDeparture() << " ->" << std::setw(4) << getDestination() << " |" << std::endl;
  std::cout << "      | Class:                      " << std::setw(9) << m_priority << " |" << std::endl;
  std::cout << "      | Seat:                         " << std::setw(7) << m_seatAssignment << " |" << std::endl;
  std::cout << "      | Date:                         " << std::setw(7) << m_date << " |" << std::endl;
  std::cout << "      | Flight Time:                  " << std::setw(7) << getBookingDepartTime() << " |" << std::endl;
  std::cout << "      | Flight ID:                    " << std::setw(7) << getFlightID() << " |" << std::endl;
  std::cout << "      | Passenger ID:                 " << std::setw(7) << getPassengerID() << " |" << std::endl;
  std::cout << "      | Price:                        " << "$" << std::setw(6) << getPrice() << " |" << std::endl;
  std::cout << "      |.......................................|" << std::endl;
}

/* ------------------------------------------------------------- */

void Booking::updateBooking(const std::string _type, std::string& _change) //dest, seat, priority
{
  if (_type == "Destination")
  {
    m_destination = _change;
    return;
  }
  if (_type == "Seat")
  {
    m_seatAssignment = _change;
    return;
  }
  if (_type == "Priority")
  {
    m_priority = _change;
    return;
  }
  else
  {
    throw("Invalid input.");
  }
}

/* ------------------------------------------------------------- */

void Booking::updateBooking(const std::string _type, float _change) //time, price
{
  if (_type == "Time")
  {
    m_flightTime = _change;
    return;
  }
  if (_type == "Price")
  {
    m_price = _change;
    return;
  }
  else
  {
    throw("Invalid input.");
  }
}

/* ------------------------------------------------------------- */
