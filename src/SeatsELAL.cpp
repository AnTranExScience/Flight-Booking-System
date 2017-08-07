#include <string>
#include <cstdio>
#include <iostream>
#include <list>
#include <cstdlib>
#include "SeatsELAL.h"
#include "Seat.h"

std::string SeatsELAL::m_defaultPlaneType = "Airbus A340-300";

/* ------------------------------------------------------------- */

SeatsELAL::SeatsELAL(){}

/* ------------------------------------------------------------- */

void SeatsELAL::SetPlaneType(std::string& _plane)
{
  m_planeType = _plane;
  setPlaneInfo();
  return;
}

/* ------------------------------------------------------------- */

void SeatsELAL::setPlaneInfo()
{
  setAvailableFirstClassSeats();
  if (m_planeType == "Airbus A340-300")
  {
    m_totalSeatsAvailable = 267;
    setAvailableEconomySeats(267);
    return;
  }
  if (m_planeType == "Airbus A340-500")
  {
    m_totalSeatsAvailable = 313;
    setAvailableEconomySeats(313);
    return;
  }
  if (m_planeType == "Boeing 777-200")
  {
    m_totalSeatsAvailable = 400;
    setAvailableEconomySeats(400);
    return;
  }
  if (m_planeType == "Boeing 777-300")
  {
    m_totalSeatsAvailable = 451;
    setAvailableEconomySeats(451);
    return;
  }
  if (m_planeType == "Boeing 747-400")
  {
    m_totalSeatsAvailable = 624;
    setAvailableEconomySeats(624);
    return;
  }
  else
  {
    m_planeType = m_defaultPlaneType;
    m_totalSeatsAvailable = 267;
    setAvailableEconomySeats(267);
    return;
  }
}

/* ------------------------------------------------------------- */

void SeatsELAL::setAvailableFirstClassSeats()
{
  m_availableFirstClassSeats = 72;
  const char* seatLetters[9] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
  char buffer[2];
  std::string seat;

  for (int row = 1, i = 0; row <= 9 ; i+=8) // setting all the first class seats
  {
    for (int i = 0; i < 9; ++i)
    {
      seat = seatLetters[i];
      sprintf(buffer, "%d", row);
      seat = buffer + seat;
      m_firstClass.push_back(Seat(seat));
    }
    row++;
  }
}

/* ------------------------------------------------------------- */

void SeatsELAL::setAvailableEconomySeats(size_t _numSeats)
{
  m_availableEconomySeats = _numSeats - 72;
  const char* seatLetters[9] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
  char buffer[5];
  std::string seat;

  for (int row = 10, i = 0; row <= _numSeats/9 ; i+=9) // setting all the first class seats
  {
    for (int i = 0; i < 9; ++i)
    {
      seat = seatLetters[i];
      sprintf(buffer, "%d", row);
      seat = buffer + seat;
      m_economyClass.push_back(Seat(seat));
    }
    row++;
  }
}
/* ------------------------------------------------------------- */

std::string SeatsELAL::GetRandomSeat(std::string _type)
{
  int num, i;
  std::list<Seat>::iterator it;

  if (_type == "Priority")
  {
   for(it = m_firstClass.begin(); it != m_firstClass.end(); it++)
   {
    if (it->isAvailable() == true)
    {
      return it->getSeatName();
    }
  }
  return it->getSeatName();
}

for(it = m_economyClass.begin(); it != m_economyClass.end(); it++)
{
  if (it->isAvailable() == true)
  {
    return it->getSeatName();
  }
}
return it->getSeatName();
}
/* ------------------------------------------------------------- */

const std::string SeatsELAL::AssignRandomEconomySeat(bool _isStartUp)
{
  std::list<Seat>::iterator it;
  std::string newSeat = "";
  while (m_availableFirstClassSeats != 0)
  {
    std::string newSeat;

    newSeat = GetRandomSeat("Economy");

    it = getEconomyClassIterator(newSeat);
    if (true == it->isAvailable())
    {
      it->setUnavailable();
      if (_isStartUp != true)
      {
        std::cout << "You've reserved seat "<< it->getSeatName() << std::endl;
        std::cout << "Check out your bookings to review your purchase." << std::endl;
      }
      it->setUnavailable();
      return newSeat;
    }

    else if (false == it->isAvailable())
    {
      newSeat = GetRandomSeat("Economy");
    }

    m_availableFirstClassSeats--;
  }

  return newSeat;
}

/* ------------------------------------------------------------- */

const std::string SeatsELAL::AssignRandomFirstClassSeat(bool _isStartUp)
{
  std::list<Seat>::iterator it;
  std::string newSeat = "";
  while (m_availableFirstClassSeats != 0)
  {
    std::string newSeat;

    newSeat = GetRandomSeat("Priority");

    it = getFirstClassIterator(newSeat);
    if (true == it->isAvailable())
    {
      it->setUnavailable();
      if (_isStartUp != true)
      {
        std::cout << "You've reserved seat "<< it->getSeatName() << std::endl;
        std::cout << "Check out your bookings to review your purchase." << std::endl;
      }
      it->setUnavailable();
      return newSeat;
    }

    else if (false == it->isAvailable())
    {
      newSeat = GetRandomSeat("Priority");
    }

    m_availableFirstClassSeats--;
  }

  return newSeat;
}

/* ------------------------------------------------------------- */

bool  SeatsELAL::AssignRequestedSeat(const std::string& _seat, const std::string& _priority, bool _isStartUp)
{
  std::list<Seat>::iterator it;
  if (_priority == "")
  {
    return false;
  }

  if (_priority == "Priority")
  {
    it = getFirstClassIterator(_seat);
    if (true == it->isAvailable())
    {
      it->setUnavailable();
      if (_isStartUp != true)
      {
        std::cout << "You've reserved seat "<< it->getSeatName() << std::endl;
        std::cout << "Check out your bookings to review your purchase." << std::endl;
      }
      return true;
    }
    else if (false == it->isAvailable())
    {
      if (_isStartUp != true)
      {
        std::cout << "We couldn't reserve seat "<< it->getSeatName() << std::endl;
      }
      return false;
    }
    else
    {
      throw("Seat doesn't exist.");
    }
  }

  if (_priority == "Economy")
  {
    it = getEconomyClassIterator(_seat);
    if (true == it->isAvailable())
    {
      it->setUnavailable();
      if (_isStartUp != true)
      {
        std::cout << "You've reserved seat "<< it->getSeatName() << std::endl;
        std::cout << "Check out your bookings to review your purchase." << std::endl;
      }
      return true;
    }
    else if (false == it->isAvailable())
    {
      if (_isStartUp != true)
      {
        std::cout << "We couldn't reserve seat "<< it->getSeatName() << std::endl;
      }
      return false;
    }
    else
    {
      throw("Seat doesn't exist.");
    }
  }

  else
  {
    return false;
  }
}

/* ------------------------------------------------------------- */

void SeatsELAL::setSeatAvailable(std::string _seat, std::string _priority)
{
  if (_priority == "Priority")
  {
    for (std::list<Seat>::iterator it = m_firstClass.begin(); it != m_firstClass.end(); ++it)
    {
      if (it->getSeatName() == _seat)
      {
        it->setAvailable();
      }
    }
  }

  for (std::list<Seat>::iterator it = m_economyClass.begin(); it != m_economyClass.end(); ++it)
  {
    if (it->getSeatName() == _seat)
    {
      it->setAvailable();
    }
  }
}

/* ------------------------------------------------------------- */

std::list<Seat>::iterator SeatsELAL::getFirstClassIterator(std::string _seat)
{
  std::list<Seat>::iterator it;
  for (it = m_firstClass.begin(); it != m_firstClass.end(); ++it)
  {
    if (it->getSeatName() == _seat)
    {
      return it;
    }
  }
  return it;
}

/* ------------------------------------------------------------- */

std::list<Seat>::iterator SeatsELAL::getEconomyClassIterator(std::string _seat)
{
  std::list<Seat>::iterator it;
  for (it = m_economyClass.begin(); it != m_economyClass.end(); ++it)
  {
    if (it->getSeatName() == _seat)
    {
      return it;
    }
  }
  return it;
}

/* ------------------------------------------------------------- */

void SeatsELAL::PrintAvaliableEconomySeats()
{
  std::list<Seat>::const_iterator it = m_economyClass.begin();
  std::cout << "                                          ECONOMY CLASS  " << std::endl;
  std::cout << "      _______________________________________________________________________________" << std::endl;
  while(it != m_economyClass.end())
  {
    std::cout << "      ||    ";
    for (int i = 0; i < 2; ++i)
    {
      for (int i = 0; i < 3; ++i)
      {
        if (it->isAvailable() == true)
        {
          std::cout << it->getSeatName() << "    ";
        }
        else if (it->isAvailable() == false)
        {
          std::cout << " *     ";
        }

        it++;
      }

      std::cout << "    ";
    }

    for (int i = 0; i < 3; ++i)
    {
      if (it->isAvailable() == true)
      {
        std::cout << it->getSeatName() << "    ";
      }
      else if (it->isAvailable() == false)
      {
        std::cout << " *     ";
      }

      it++;
    }

    std::cout << "||";

    std::cout << std::endl;
  }
  std::cout << "      _______________________________________________________________________________" << std::endl;
}

/* ------------------------------------------------------------- */

void SeatsELAL::PrintAvaliableFirstClassSeats()
{
  std::cout << "      _______________________________________________________________________________" << std::endl;
  std::cout << "                                         FIRST CLASS  " << std::endl;
  std::list<Seat>::const_iterator it = m_firstClass.begin();
  while(it != m_firstClass.end())
   {
    std::cout << "      ||     ";
    for (int i = 0; i < 2; ++i)
    {
      for (int i = 0; i < 3; ++i)
      {
        if (it->isAvailable() == true)
        {
          std::cout << it->getSeatName() << "    ";
        }
        else if (it->isAvailable() == false)
        {
          std::cout << " *    ";
        }

        it++;
      }

      std::cout << "       ";
    }

    for (int i = 0; i < 3; ++i)
    {
      if (it->isAvailable() == true)
      {
        std::cout << it->getSeatName() << "    ";
      }
      else if (it->isAvailable() == false)
      {
        std::cout << " *    ";
      }

      it++;
    }

    std::cout << "  ||";

    std::cout << std::endl;
  }
  std::cout << "      _______________________________________________________________________________" << std::endl;
}

/* ------------------------------------------------------------- */
