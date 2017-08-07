#include <iostream>
#include "FilterImpl.h"
#include "Price_Filter_Impl.h"

/* ------------------------------------------------------------- */

void PriceFilterImpl::RunFilter()
{
  float userChoice1, userChoice2;
  float userPassword;
  std::cout << "Set starting Price:" << std::endl;
  std::cin  >> userChoice1;
  std::cout << "Set ending Price:" << std::endl;
  std::cin  >> userChoice2;
  setParams(userChoice1, userChoice2);
}

/* ------------------------------------------------------------- */

bool PriceFilterImpl::Filter(PassengerFlightInfo _FI)
{
  if (_FI.m_flightID == "")
  {
    return false;
  }
  return (m_first <= _FI.m_price <= m_second) ? true : false;
}

/* ------------------------------------------------------------- */
