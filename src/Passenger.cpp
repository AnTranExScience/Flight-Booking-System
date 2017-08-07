#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include "Passenger.h"

/* ------------------------------------------------------------- */

void Passenger::printInfo() const
{
  std::cout << std::endl << "      |............................|" << std::endl;
  std::cout << "      | Passenger ID:      " << std::setw(7) << getID() << " |" << std::endl;
  std::cout << "      | Name:         " << std::setw(7) << getName() << " |" << std::endl;
  std::cout << "      | Number:            " << std::setw(7) << getNumber() << " |" << std::endl;
  std::cout << "      | Address:           " << std::setw(7) << getAddress() << " |" << std::endl;
  std::cout << "      |............................|" << std::endl;
}

/* ------------------------------------------------------------- */

Passenger::Passenger(const Passenger& _exP):m_name(_exP.m_name), m_address(_exP.m_address), m_ID(_exP.m_ID), m_number(_exP.m_number){};

/* ------------------------------------------------------------- */
