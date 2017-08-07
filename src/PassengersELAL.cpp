#include <iostream>
#include "PassengersELAL.h"

PassengersELAL PassengersELAL::pm ; // init static data , has to be in CPP file, not in H file

/* ------------------------------------------------------------- */

PassengersELAL::~PassengersELAL()
{
  std::list<Passenger*>::iterator it;
  for (it = m_passengers.begin(); it != m_passengers.end(); it++)
  {
    delete *it;
    m_passengers.erase(it);
  }
};

/* ------------------------------------------------------------- */

void PassengersELAL::printAllPassengers() const
{
  std::list<Passenger*>::const_iterator it;
  for (it = m_passengers.begin(); it != m_passengers.end(); ++it)
  {
    (*it)->printInfo();
  }
}

/* ------------------------------------------------------------- */

void PassengersELAL::createNewPassenger(std::string& _name, std::string& _add, long _id, long _ph)
{
  m_passengers.push_back(new Passenger(_name, _add, _id, _ph));
}

/* ------------------------------------------------------------- */

void PassengersELAL::printPassenger(long _passengerID)
{
  std::list<Passenger*>::iterator it = returnIterator(_passengerID);
  (*it)->printInfo();
}

/* ------------------------------------------------------------- */

void PassengersELAL::deleteExistingPassenger(long _id)
{
  std::list<Passenger*>::iterator it= m_passengers.begin();
  while(it != m_passengers.end())
  {
    if ((*it)->getID() == _id)
    {
      delete *it;
      m_passengers.erase(it++);
      return;
    }
    ++it;
  }
}

/* ------------------------------------------------------------- */

void PassengersELAL::updateAddress(long _id, std::string _s)
{
  std::list<Passenger*>::iterator it = returnIterator(_id);
  (*it)->updateAddress(_s);
}

/* ------------------------------------------------------------- */

void PassengersELAL::updateName(long _id, std::string _s)
{
  std::list<Passenger*>::iterator it = returnIterator(_id);
  (*it)->updateName(_s);
}

/* ------------------------------------------------------------- */

void PassengersELAL::updateNumber(long _id, long _l)
{
  std::list<Passenger*>::iterator it = returnIterator(_id);
  (*it)->updateNumber(_l);
}

/* ------------------------------------------------------------- */

std::list<Passenger*>::iterator PassengersELAL::returnIterator(long _id)
{
  std::list<Passenger*>::iterator it;
  for (it = m_passengers.begin(); it != m_passengers.end(); ++it)
  {
    if ((*it)->getID() == _id)
    {
      return it;
    }
  }
  throw("Passenger Not Found");
}

/* ------------------------------------------------------------- */
