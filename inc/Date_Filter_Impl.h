#ifndef __Date_Filter_IMPL_H__
#define __Date_Filter_IMPL_H__

#include "FlightInfo.h"
#include "FilterImpl.h"

class DateFilterImpl : public IFilter
{
public:
  DateFilterImpl(){RunFilter();}
  ~DateFilterImpl(){};
  virtual void RunFilter();
  bool Filter(PassengerFlightInfo _FI);
  inline void setParams(std::string _param1, std::string _param2);

private:
	std::string AddZero(std::string _userDate);
  std::string m_first;
  std::string m_second;
};

inline void DateFilterImpl::setParams(std::string _param1, std::string _param2) {m_first = _param1; m_second = _param2;}

#endif /* __Date_Filter_IMPL_H__ */
