#ifndef __Departure_Filter_IMPL_H__
#define __Departure_Filter_IMPL_H__

#include "FilterImpl.h"

class FlightInfo;

class DepartureFilterImpl : public IFilter
{
public:
  DepartureFilterImpl(){RunFilter();}
  ~DepartureFilterImpl(){};
  virtual void RunFilter();
  bool Filter(PassengerFlightInfo _FI);
  inline void setParam(std::string _param);

private:
  std::string m_param;
};

inline void DepartureFilterImpl::setParam(std::string _param) {m_param = _param;}

#endif /* __Departure_Filter_IMPL_H__ */
