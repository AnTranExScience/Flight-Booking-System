#ifndef __Destination_Filter_IMPL_H__
#define __Destination_Filter_IMPL_H__

#include "FilterImpl.h"

class FlightInfo;
class Destination;

class DestinationFilterImpl : public IFilter
{
public:
  DestinationFilterImpl(){RunFilter();};
  ~DestinationFilterImpl(){};
  virtual void RunFilter();
  bool Filter(PassengerFlightInfo _FI);
  inline void setParam(std::string _param);

private:
  std::string m_param;
};

inline void DestinationFilterImpl::setParam(std::string _param) {m_param = _param;}

#endif /* __Destination_Filter_IMPL_H__ */
