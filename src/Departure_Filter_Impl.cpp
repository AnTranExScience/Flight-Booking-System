#include <iostream>
#include <string>

#include "FilterImpl.h"
#include "Departure_Filter_Impl.h"

/* ------------------------------------------------------------- */

void DepartureFilterImpl::RunFilter()
{
  std::string userChoice;
  std::string userPassword;
  std::cout << "What Departure are you looking for?" << std::endl;
  std::cin  >> userChoice;
  setParam(userChoice);
}

/* ------------------------------------------------------------- */

bool DepartureFilterImpl::Filter(PassengerFlightInfo _FI)
{
  if (_FI.m_flightID == "")
  {
    return false;
  }

  return (_FI.m_departure == m_param) ? true : false;
}

/* ------------------------------------------------------------- */
