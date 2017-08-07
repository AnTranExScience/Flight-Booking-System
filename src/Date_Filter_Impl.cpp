#include <iostream>
#include <cstring>
#include <string>

#include "FilterImpl.h"
#include "Date_Filter_Impl.h"

/* ------------------------------------------------------------- */

void DateFilterImpl::RunFilter()
{
  std::string userStartMonth, userEndMonth, userStartDate, userEndDate;
  std::string fullStart, fullEnd;
  std::cout << "Set the month of the starting date:" << std::endl;
  std::cin  >> userStartMonth;
  std::cout << "Set the day of the starting date:" << std::endl;
  std::cin  >> userStartDate;
  std::cout << "Set the month of the ending date:" << std::endl;
  std::cin  >> userEndMonth;
  std::cout << "Set the day of the ending date:" << std::endl;
  std::cin  >> userEndDate;
  userStartMonth = AddZero(userStartMonth);
  userEndMonth = AddZero(userEndMonth);
  userStartDate = AddZero(userStartDate);
  userEndDate = AddZero(userEndDate);

  fullStart = userStartMonth + "/" + userStartDate;
  fullEnd = userEndMonth + "/" + userEndDate;
  setParams(fullStart, fullEnd);
}

/* ------------------------------------------------------------- */

bool DateFilterImpl::Filter(PassengerFlightInfo _FI)
{
  if (_FI.m_flightID == "")
  {
    return false;
  }

  if (m_first <= _FI.m_date)
  {
    if (_FI.m_date <= m_second)
    {
      return true;
    }
  }
  return false;
}

/* ------------------------------------------------------------- */

std::string DateFilterImpl::AddZero(std::string _userDate)
{
	std::string userDate;
  if (1 >= strlen(_userDate.c_str()))
  {
		userDate = "0" + _userDate;
		return userDate;
  }
	return _userDate;
}

/* ------------------------------------------------------------- */
