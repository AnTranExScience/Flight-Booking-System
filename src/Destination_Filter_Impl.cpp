#include <iostream>
#include "FilterImpl.h"
#include "Destination_Filter_Impl.h"

/* ------------------------------------------------------------- */

void DestinationFilterImpl::RunFilter()
{
  std::string userChoice;
  std::cout << "What destination are you looking for?" << std::endl;
  std::cin  >> userChoice;
  setParam(userChoice);
}

/* ------------------------------------------------------------- */

bool DestinationFilterImpl::Filter(PassengerFlightInfo _FI)
{
  if (_FI.m_flightID == "")
  {
    return false;
  }

  return (_FI.m_destination == m_param) ? true : false;
}

/* ------------------------------------------------------------- */
