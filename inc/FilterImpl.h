#ifndef __Filter_IMPL_H__
#define __Filter_IMPL_H__

#include <string>
#include "FlightInfo.h"

class IFilter
{
public:
  IFilter(){};
  virtual ~IFilter();
  virtual void RunFilter() = 0;
  virtual bool Filter(PassengerFlightInfo _FI) = 0;

protected:
  IFilter*  m_Filter;
};

#endif /* __FilterIMPL_H__ */
