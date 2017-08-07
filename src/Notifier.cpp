#include <iostream>
#include <list>
#include <vector>

#include "Notifier.h"
#include "PassengersELAL.h"
#include "BookingsELAL.h"
#include "FlightsELAL.h"
#include "FlightInfo.h"
#include "Filter_Factory.h"
#include "Destination_Filter_Impl.h"
#include "Departure_Filter_Impl.h"
#include "Date_Filter_Impl.h"
#include "Price_Filter_Impl.h"
#include "FilterImpl.h"
#include "UI_Factory.h"

Notifier Notifier::m_nf;

/* ------------------------------------------------------------- */

void Notifier::setPointers(PassengersELAL* _pman, FlightsELAL* _fman, BookingsELAL* _bman)
{
  m_pMan = _pman;
  m_fMan = _fman;
  m_bMan = _bman;
}

/* ------------------------------------------------------------- */

void Notifier::NotifyNewFlight(FlightInfo& _fi) //not by value
{
  bool retVal = m_fMan->isFlightIDUnique(_fi.m_flightID);
  if (retVal == false)
  {
    std::cout << "Please try again with unique flight ID. This one is taken." << std::endl;
  }
  m_fMan->createNewFlight(_fi);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyNewBooking(long _passengerID, std::string& _flightID, std::string& _seat, std::string& _priority, bool _isStartUp)
{
  std::string res = _seat;
  if ((_seat == "") && (_priority == "Economy"))
  {
    res = m_fMan->AssignRandomEconomySeat(_flightID, _isStartUp);
  }
  else if ((_seat == "") && (_priority == "Priority"))
  {
    res = m_fMan->AssignRandomFirstClassSeat(_flightID, _isStartUp);
  }
  else
  {
    m_fMan->AssignRequestedSeat(_flightID, _seat, _priority, _isStartUp);
  }
  PassengerFlightInfo fi1 = m_fMan->getFlightInfo(_flightID);
  m_bMan->createNewBooking(_passengerID, _flightID, fi1, res, _priority);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyPassengerChange(std::string _type, long _id, std::string _s)
{
  if ((_type != "Address") && (_type != "Name"))
  {
    throw("Invalid Passenger Change");
  }

  if (_type == "Address")
  {
    m_pMan->updateAddress(_id, _s);
  }

  if (_type == "Name")
  {
    m_pMan->updateName(_id, _s);
  }
  return;
}

/* ------------------------------------------------------------- */

void Notifier::FilterFlights()
{
  FilterFactory u1;
  std::list<Flight*> m_list = m_fMan->GetListOfFlights();
  std::vector<IFilter*> m_filters;
  int userChoice;

  std::cout << "Filter by Destination? (1) yes, (2) no" << std::endl;
  std::cin >> userChoice;

  if (userChoice == 1)
  {
    m_filters.push_back(u1.CreateFilter("Destination"));
  }
  std::cout << "Filter by Departure? (1) yes, (2) no" << std::endl;
  std::cin >> userChoice;

  if (userChoice == 1)
  {
    m_filters.push_back(u1.CreateFilter("Departure"));
  }
  std::cout << "Filter by Date? (1) yes, (2) no" << std::endl;
  std::cin >> userChoice;

  if (userChoice == 1)
  {
    m_filters.push_back(u1.CreateFilter("Date"));
  }
  std::cout << "Filter by Price? (1) yes, (2) no" << std::endl;
  std::cin >> userChoice;

  if (userChoice == 1)
  {
    m_filters.push_back(u1.CreateFilter("Price"));
  }

  std::vector<IFilter*>::iterator filter;
  std::list<Flight*>::iterator flight;
  std::list<Flight*> results;
  int deleteFlag;
  for(flight = m_list.begin(); flight != m_list.end(); flight++)
  {
    deleteFlag = false;
    for(filter = m_filters.begin(); filter != m_filters.end(); filter++)
    {
      PassengerFlightInfo pf1 = (*flight)->getFlightInfo();
      bool retVal = (*filter)->Filter(pf1);
      if (retVal == false)
      {
        deleteFlag = true;
      }
    }
    if (deleteFlag == false)
    {
      PassengerFlightInfo pf1 = (*flight)->getFlightInfo();
      results.push_back(*flight);
    }
  }

  std::cout << std::endl << std::endl << "**** SEARCH RESULTS: ****" << std::endl;
  std::list<Flight*>::iterator flight2 = results.begin();
  while (flight2 != results.end())
  {
    (*flight2)->printInfo();
    flight2++;
  }
}

/* ------------------------------------------------------------- */

void Notifier::GetAllCurrentFlight()
{
  std::list<Flight*> allFlights = m_fMan->GetListOfFlights();
  std::list<Flight*>::iterator flight = allFlights.begin();
  while (flight != allFlights.end())
  {
    PassengerFlightInfo pf1 = (*flight)->getFlightInfo();
    (*flight)->printInfo();
    flight++;
  }
}

/* ------------------------------------------------------------- */

void Notifier::NotifyDeleteBooking(long _bookingID)
{
  PassengerFlightInfo seat;
  seat = m_bMan->deleteExistingBooking(_bookingID);
  m_fMan->SetSeatAvailable(seat.m_flightID, seat.m_seatAssignment, seat.m_priority);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyDeletePassenger(long _id)
{
  m_bMan->deleteAllBookingsByID(_id);
  m_pMan->deleteExistingPassenger(_id);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyNewPassenger(std::string& _name, std::string& _add, long _id, long _ph)
{
  m_pMan->createNewPassenger(_name, _add, _id, _ph);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyFlightChange(std::string& _type, std::string& _id, std::string& _s)
{
  std::string type = "Destination";
  m_fMan->updateDestination(_id, _s);
  m_bMan->updateFlightBooking(_type, _id, _s);
}

/* ------------------------------------------------------------- */

void Notifier::GetFlightInfo(std::string& _flightID)
{
  m_fMan->printFlightInfo(_flightID);
}

/* ------------------------------------------------------------- */

void Notifier::GetSeatingChart(std::string& _class, std::string& _flightID)
{
  m_fMan->printAllSeats(_flightID);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyFlightChange(std::string& _type, std::string& _id, float _f)
{
  m_fMan->update(_type, _id, _f);
  m_bMan->updateFlightBooking(_type, _id, _f);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyFlightCapacityChange(std::string& _id, size_t _t)
{
  m_fMan->updateSeatCapacity(_id, _t);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyBookingChange(std::string _type, long _passengerID, std::string& _flightID, std::string& _change) //dest,seat,priority
{
  m_bMan->updateBooking(_type, _passengerID, _flightID, _change);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyBookingChange(std::string _type, long _passengerID, std::string& _flightID, float _change) //time,price
{
  m_bMan->updateBooking(_type, _passengerID, _flightID, _change);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyPassengerNumberChange(long _id, long _s)
{
  m_pMan->updateNumber(_id, _s);
}

/* ------------------------------------------------------------- */

void Notifier::NotifyDeleteFlight(std::string& _id)
{
  m_bMan->deleteAllBookingsByID(_id);
  m_fMan->deleteExistingFlight(_id);
}

/* ------------------------------------------------------------- */

void Notifier::GetAllCurrentPassengers()
{
  m_pMan->printAllPassengers();
}

/* ------------------------------------------------------------- */

void Notifier::GetAllBookingsByFlight(std::string& _flightID)
{
  m_bMan->printBookingsByFlight(_flightID);
}
/* ------------------------------------------------------------- */

void Notifier::GetAllBookings()
{
  m_bMan->printAllBookings();
}

/* ------------------------------------------------------------- */

void Notifier::GetAllBookingsByPassenger(long _passengerID)
{
  m_bMan->printBookingsByPassenger(_passengerID);
}

/* ------------------------------------------------------------- */

void Notifier::GetInfoByPassenger(long _passengerID)
{
  m_pMan->printPassenger(_passengerID);
}

/* ------------------------------------------------------------- */
