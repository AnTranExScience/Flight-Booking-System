#ifndef __Price_Filter_IMPL_H__
#define __Price_Filter_IMPL_H__

#include <iostream>
#include <string>
#include "FilterImpl.h"

class FlightInfo;

class PriceFilterImpl : public IFilter
{
public:
  PriceFilterImpl(){RunFilter();}
  ~PriceFilterImpl(){};
  virtual void RunFilter();
  bool Filter(PassengerFlightInfo _FI);
  inline void setParams(float _param1, float _param2);

private:
  float m_first;
  float m_second;
};

inline void PriceFilterImpl::setParams(float _param1, float _param2) {m_first = _param1; m_second = _param2;}

#endif /* __Price_Filter_IMPL_H__ */
