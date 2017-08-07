#ifndef __BOOKINGSELAL_H__
#define __BOOKINGSELAL_H__

#include <list>
#include <string>

#include "Booking.h"
#include "FlightInfo.h"

class Booking;

class BookingsELAL
{
public:
  inline static BookingsELAL& createObj() {return pm;};

  void createNewBooking(long _passengerID, std::string& _flightID, const PassengerFlightInfo _fI, std::string& _seat, std::string& _priority);
  PassengerFlightInfo deleteExistingBooking(long _bookingID);
  void deleteExistingBooking(long _passengerID, std::string& _id);
  void deleteAllBookingsByID(long _passengerID); //for deleted passenger
  void deleteAllBookingsByID(std::string& _id);  //for deleted flight

  void updateBooking(const std::string _type, long _passID, std::string& _flightID, std::string& _change); //dest,seat,priority
  void updateBooking(const std::string _type, long _passID, std::string& _flightID, float _change); //time,price
  void updateFlightBooking(std::string& _type, std::string& _flightID, std::string& _s); //dest
  void updateFlightBooking(std::string& _type, std::string& _flightID, float _t);   //time

  void printAllBookings() const;
  void printBookingsByFlight(std::string& _flight) const;
  void printBookingsByPassenger(long _passengerID) const;

private:
  static BookingsELAL pm;
  std::list<Booking*> m_Bookings;
  static long         m_bookingID;

  BookingsELAL(){}
  inline ~BookingsELAL();
  BookingsELAL(const BookingsELAL&);
  void operator=(BookingsELAL&);
};

inline BookingsELAL::~BookingsELAL()
{
  std::list<Booking*>::iterator it;
  for (it = m_Bookings.begin(); it != m_Bookings.end(); it++)
  {
    delete *it;
    m_Bookings.erase(it);
  }
};

#endif /* __BOOKINGSELAL_H__ */
