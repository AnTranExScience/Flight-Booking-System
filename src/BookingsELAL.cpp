#include <list>
#include <iostream>
#include "Booking.h"
#include "BookingsELAL.h"
#include "FlightInfo.h"

/* ------------------------------------------------------------- */

BookingsELAL BookingsELAL::pm; // init static data , has to be in CPP file, not in H file
long BookingsELAL::m_bookingID = 1;

/* ------------------------------------------------------------- */

void BookingsELAL::createNewBooking(long _passengerID, std::string& _flightID, PassengerFlightInfo _fI, std::string& _seat, std::string& _priority)
{
  m_Bookings.push_back(new Booking(m_bookingID, _passengerID, _fI, _seat, _priority));
  m_bookingID++;
}

/* ------------------------------------------------------------- */

PassengerFlightInfo BookingsELAL::deleteExistingBooking(long _bookingID)
{
  PassengerFlightInfo pfi;
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if ((*it)->getBookingID() == _bookingID)
    {
      pfi.m_flightID = (*it)->getFlightID();
      pfi.m_departure = (*it)->getDeparture();
      pfi.m_destination = (*it)->getDestination();
      pfi.m_flightTime = (*it)->getBookingDepartTime();
      pfi.m_date = (*it)->getDate();
      pfi.m_price = (*it)->getPrice();
      pfi.m_seatAssignment = (*it)->getSeatAssignment();
      pfi.m_priority = (*it)->getPriority();

      delete *it;
      m_Bookings.erase(it);
    }
  }
  return pfi;
}

/* ------------------------------------------------------------- */

void BookingsELAL::updateFlightBooking(std::string& _type, std::string& _flightID, std::string& _s)
{
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if ((*it)->getFlightID() == _flightID)
    {
      (*it)->updateBooking(_type, _s);
    }
  }
}

/* ------------------------------------------------------------- */

void BookingsELAL::updateFlightBooking(std::string& _type, std::string& _flightID, float _t)
{
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if ((*it)->getFlightID() == _flightID)
    {
      (*it)->updateBooking(_type, _t);
    }
  }
}


/* ------------------------------------------------------------- */

void BookingsELAL::printBookingsByFlight(std::string& _flight) const
{
  std::list<Booking*>::const_iterator it;
  std::cout << std::endl << "** ALL BOOKINGS FOR FLIGHT " << _flight  << " **"<< std::endl;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if ((*it)->getFlightID() == _flight)
    {
      (*it)->printInfo();
    }
  }
}

/* ------------------------------------------------------------- */

void BookingsELAL::printBookingsByPassenger(long _passengerID) const
{
  std::list<Booking*>::const_iterator it;
  std::cout << std::endl << "** ALL BOOKINGS FOR PASSENGER " << _passengerID << " **"<< std::endl;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if ((*it)->getPassengerID() == _passengerID)
    {
      (*it)->printInfo();
    }
  }
}

/* ------------------------------------------------------------- */

void BookingsELAL::deleteExistingBooking(long _passengerID, std::string& _id)
{
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if (((*it)->getPassengerID() == _passengerID) && ((*it)->getFlightID() == _id))
    {
      delete *it;
      m_Bookings.erase(it);
    }
  }
}

/* ------------------------------------------------------------- */

void BookingsELAL::deleteAllBookingsByID(long _passengerID)
{
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if ((*it)->getPassengerID() == _passengerID)
    {
      delete *it;
      m_Bookings.erase(it);
    }
  }
}

/* ------------------------------------------------------------- */

void BookingsELAL::deleteAllBookingsByID(std::string& _id)
{
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if ((*it)->getFlightID() == _id)
    {
      delete *it;
      m_Bookings.erase(it);
    }
  }
}

/* ------------------------------------------------------------- */

void BookingsELAL::updateBooking(const std::string _type, long _passID, std::string& _flightID, std::string& _change)
{
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if (((*it)->getPassengerID() == _passID) && ((*it)->getFlightID() == _flightID))
    {
      (*it)->updateBooking(_type, _change);
    }
  }
}

/* ------------------------------------------------------------- */

void BookingsELAL::updateBooking(const std::string _type, long _passID, std::string& _flightID, float _change)
{
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    if (((*it)->getPassengerID() == _passID) && ((*it)->getFlightID() == _flightID))
    {
      (*it)->updateBooking(_type, _change);
    }
  }
}

/* ------------------------------------------------------------- */

void BookingsELAL::printAllBookings() const
{
  std::list<Booking*>::const_iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); ++it)
  {
    (*it)->printInfo();
  }
}

/* ------------------------------------------------------------- */
