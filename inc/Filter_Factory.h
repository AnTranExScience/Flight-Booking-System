#ifndef __Filter_FACTORY_H__
#define __Filter_FACTORY_H__

#include <iostream>
#include "Destination_Filter_Impl.h"
#include "Departure_Filter_Impl.h"
#include "Date_Filter_Impl.h"
#include "Price_Filter_Impl.h"

class Filter_Factory;
class FilterImpl;


class FilterFactory {
public:
  FilterFactory(){};
  ~FilterFactory(){};

  static IFilter* CreateFilter(const std::string& Impl)
  {
    IFilter* ptrFilter = 0;
      if (Impl == "Destination")
      {
        ptrFilter = new DestinationFilterImpl();
      }
      if (Impl == "Departure")
      {
        ptrFilter = new DepartureFilterImpl();
      }
      if (Impl == "Date")
      {
        ptrFilter = new DateFilterImpl();
      }
      if (Impl == "Price")
      {
        ptrFilter = new PriceFilterImpl();
      }
    return ptrFilter;
  };
};

#endif /* __FilterFACTORY_H__ */
