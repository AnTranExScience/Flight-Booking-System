#include <iostream>
#include <string>
#include "FlightInfo.h"
#include "FlightsELAL.h"

FlightsELAL FlightsELAL::pm; // init static data, has to be in CPP file, not in H file

/* ------------------------------------------------------------- */

float FlightsELAL::GetPrice(std::string& _id)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->getPrice();
}

/* ------------------------------------------------------------- */

std::string FlightsELAL::GetDate(std::string& _id)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->getDate();
}

/* ------------------------------------------------------------- */

std::string FlightsELAL::GetDefaultPlaneType(std::string& _id)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->GetDefaultPlaneType();
}

/* ------------------------------------------------------------- */

std::string FlightsELAL::GetPlaneType(std::string& _id)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->GetPlaneType();
}

/* ------------------------------------------------------------- */

void FlightsELAL::SetDefaultPlaneType(std::string& _id, std::string& _plane)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->SetDefaultPlaneType(_plane);
}

/* ------------------------------------------------------------- */

void FlightsELAL::SetPlaneType(std::string& _id, std::string& _plane)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->SetPlaneType(_plane);
}

/* ------------------------------------------------------------- */

std::string FlightsELAL::AssignRandomEconomySeat(std::string& _id, bool _isStartUp)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->AssignRandomEconomySeat(_isStartUp);
}

/* ------------------------------------------------------------- */

std::string FlightsELAL::AssignRandomFirstClassSeat(std::string& _id, bool _isStartUp)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->AssignRandomFirstClassSeat(_isStartUp);
}

/* ------------------------------------------------------------- */

bool FlightsELAL::AssignRequestedSeat(std::string& _id, const std::string& _seat, const std::string& _priority, bool _isStartUp)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  return (*it)->AssignRequestedSeat(_seat, _priority, _isStartUp);
}

/* ------------------------------------------------------------- */

void FlightsELAL::SetSeatAvailable(std::string& _flightID, std::string& _seatAssignment, std::string& _priority)
{
  std::list<Flight*>::iterator it = returnIterator(_flightID);
  return (*it)->setSeatAvailable(_seatAssignment, _priority);
}

/* ------------------------------------------------------------- */

void FlightsELAL::printAllFlights() const
{
  std::list<Flight*>::const_iterator it;
  for (it = m_Flights.begin(); it != m_Flights.end(); it++)
  {
    (*it)->printInfo();
  }
}
/* ------------------------------------------------------------- */

void FlightsELAL::printFlightInfo(std::string& _id)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  (*it)->printInfo();
}

/* ------------------------------------------------------------- */

PassengerFlightInfo FlightsELAL::getFlightInfo(const std::string& _flightID)
{
  PassengerFlightInfo FI1;
  std::list<Flight*>::iterator it = m_Flights.begin();
  while(it != m_Flights.end())
  {
    if ((*it)->getFlightID() == _flightID)
    {
      return (*it)->getFlightInfo();
    }
    it++;
  }
  return FI1;
}

/* ------------------------------------------------------------- */

void FlightsELAL::createNewFlight(FlightInfo _pfi)
{
  m_Flights.push_back(new Flight(_pfi));
}

/* ------------------------------------------------------------- */

bool FlightsELAL::isFlightIDUnique(const std::string& _newID) const
{
  std::list<Flight*>::const_iterator it = m_Flights.begin();
  while(it != m_Flights.end())
  {
    if ((*it)->getFlightID() == _newID)
    {
      return false;
    }
    *it++;
  }
  return true;
}

/* ------------------------------------------------------------- */

void FlightsELAL::deleteExistingFlight(std::string& _id)
{
  std::list<Flight*>::iterator it = m_Flights.begin();
  while(it != m_Flights.end())
  {
    if ((*it)->getFlightID() == _id)
    {
      delete *it;
      m_Flights.erase(it);
      return;
    }
    *it++;
  }
}

/* ------------------------------------------------------------- */

void FlightsELAL::updateDestination(std::string& _id, std::string& _s)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  (*it)->updateDestination(_s);
}

/* ------------------------------------------------------------- */

void FlightsELAL::updateSeatCapacity(std::string& _id, size_t _s)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  (*it)->updateSeatCapacity(_s);
}

/* ------------------------------------------------------------- */

void FlightsELAL::update(std::string& _type, std::string& _id, float _l)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  (*it)->update(_type, _l);
}

/* ------------------------------------------------------------- */

void FlightsELAL::printEconomySeats(std::string& _id)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  (*it)->printEconomySeats();
}

/* ------------------------------------------------------------- */

void FlightsELAL::printFirstClassSeats(std::string& _id)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  (*it)->printFirstClassSeats();
}

/* ------------------------------------------------------------- */

void FlightsELAL::printAllSeats(std::string& _id)
{
  std::list<Flight*>::iterator it = returnIterator(_id);
  (*it)->printAllSeats();
}

/* ------------------------------------------------------------- */

std::list<Flight*>::iterator FlightsELAL::returnIterator(std::string& _id)
{
  std::list<Flight*>::iterator it;
  for (it = m_Flights.begin(); it != m_Flights.end(); it++)
  {
    if ((*it)->getFlightID() == _id)
    {
      return it;
    }
  }
  throw("Flight Not Found");
}

/* ------------------------------------------------------------- */
