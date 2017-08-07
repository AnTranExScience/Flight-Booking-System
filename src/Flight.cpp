#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include "Flight.h"
#include "FlightInfo.h"

/* ------------------------------------------------------------- */

Flight::Flight(FlightInfo _fi):m_flightID(_fi.m_flightID), m_flightTime(_fi.m_flightTime), m_destination(_fi.m_destination), m_departure(_fi.m_departure), m_planeType(_fi.m_planeType), m_price(_fi.m_price), m_date(_fi.m_date)
{
  m_sm.SetPlaneType(m_planeType);
};

/* ------------------------------------------------------------- */

Flight::Flight(const Flight& _exP):m_flightID(_exP.m_flightID), m_flightTime(_exP.m_flightTime), m_destination(_exP.m_destination), m_departure(_exP.m_departure), m_planeType(_exP.m_planeType), m_price(_exP.m_price), m_date(_exP.m_date)
{
  std::string pT = _exP.m_planeType;
  m_sm.SetPlaneType(pT);
};

/* ------------------------------------------------------------- */

void Flight::printInfo() const
{
  std::cout << "      |˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚˚|" << std::endl;
  std::cout << "      |           Flight " << std::setw(5) << getFlightID() << "                |" << std::endl;
  std::cout << "      | Route:                    " << std::setw(4) << getDeparture() << " ->" << std::setw(4) << getDestination() << " |" << std::endl;
  std::cout << "      | Date:                         " << std::setw(7) << getDate() << " |" << std::endl;
  std::cout << "      | Flight Time:                  " << std::setw(7) << getFlightDepartTime() << " |" << std::endl;
  std::cout << "      | Economy Class:               " << "$" << std::setw(7) << getPrice()<< " |" << std::endl;
  std::cout << "      |" <<  std::setw(3) << getAvailableFirstClassSeats() << " seats left                         |" << std::endl;
  std::cout << "      | First   Class:               " << "$" << std::setw(7) << (getPrice() * 1.5)<< " |" << std::endl;
  std::cout << "      | " << std::setw(3) << getAvailableEconomySeats() << " seats left                        |" << std::endl;
  std::cout << "      | Plane:                " << std::setw(15) << m_planeType << " |" << std::endl;
  std::cout << "      |.......................................|" << std::endl;
}

/* ------------------------------------------------------------- */

PassengerFlightInfo Flight::getFlightInfo() const
{
  PassengerFlightInfo FI1;
  FI1.m_flightID    = m_flightID;
  FI1.m_flightTime  = getFlightDepartTime();
  FI1.m_destination = getDestination();
  FI1.m_departure   = getDeparture();
  FI1.m_price       = getPrice();
  FI1.m_date        = m_date;
  return FI1;
}

/* ------------------------------------------------------------- */

void Flight::printEconomySeats()
{
  m_sm.PrintAvaliableEconomySeats();
}

/* ------------------------------------------------------------- */

void Flight::update(std::string& _type, float _f)
{
  if ((_type != "Price") && (_type != "Time"))
  {
    return;
  }

  if (_type != "Price")
  {
    m_price = _f;
  }

  else if (_type != "Time")
  {
    m_flightTime = _f;
  }
  return;
}

/* ------------------------------------------------------------- */

size_t Flight::getAvailableEconomySeats() const
{
  return m_sm.GetAvailableEconomySeats();
}

/* ------------------------------------------------------------- */

size_t Flight::getAvailableFirstClassSeats() const
{
  return m_sm.GetAvailableFirstClassSeats();
}

/* ------------------------------------------------------------- */

void Flight::getPlaneCapacity() const
{
  m_sm.GetPlaneCapacity();
}

/* ------------------------------------------------------------- */

void Flight::printFirstClassSeats()
{
  m_sm.PrintAvaliableFirstClassSeats();
}

/* ------------------------------------------------------------- */

void Flight::printAllSeats()
{
  m_sm.PrintAvaliableFirstClassSeats();
  m_sm.PrintAvaliableEconomySeats();
}

/* ------------------------------------------------------------- */
