#ifndef __NOTIFIER_H__
#define __NOTIFIER_H__

#include "FlightInfo.h"

class PassengersELAL;
class FlightsELAL;
class BookingsELAL;
class Filter_Factory;

class Notifier
{
public:
  static Notifier& createObj() {return m_nf;}

  void setPointers(PassengersELAL* _pman, FlightsELAL* _fman, BookingsELAL* _bman);
  void NotifyNewFlight(FlightInfo& _fi);
  void NotifyNewPassenger(std::string& _name, std::string& _add, long _id, long _ph);
  void NotifyNewBooking(long _passID, std::string& _flightID, std::string& _seat, std::string& _priority, bool _isStartUp);

  void FilterFlights();
  void GetAllBookings();
  void GetAllCurrentFlight();
  void GetAllCurrentPassengers();
  void GetAllBookingsByFlight(std::string& _flightID);
  void GetAllBookingsByPassenger(long _passengerID);
  void GetInfoByPassenger(long _passengerID);
  void GetFlightInfo(std::string& _flightID);
  void GetSeatingChart(std::string& _class, std::string& _flightID);

  void NotifyFlightChange(std::string& _type, std::string& _id, std::string& _s);
  void NotifyFlightChange(std::string& _type, std::string& _id, float _f);
  void NotifyFlightCapacityChange(std::string& _id, size_t _t);
  void NotifyBookingChange(std::string _type, long _passengerID, std::string& _flightID, std::string& _change); //dest,seat,priority
  void NotifyBookingChange(std::string _type, long _passengerID, std::string& _flightID, float _change); //time,price
  void NotifyPassengerChange(std::string _type, long _id, std::string _s);
  void NotifyPassengerNumberChange(long _id, long _s);

  void NotifyDeleteFlight(std::string& _id);
  void NotifyDeleteBooking(long _passID, std::string& _flightID);
  void NotifyDeleteBooking(long _passID);
  void NotifyDeletePassenger(long _id);

private:
  PassengersELAL* m_pMan; //use ptrs to interface
  FlightsELAL*    m_fMan;
  BookingsELAL*   m_bMan;
  static Notifier   m_nf;

  Notifier(){};
  ~Notifier(){};
  Notifier(const Notifier&);
  void operator=(Notifier&);
};

#endif /* __NOTIFIER_H__ */
