#ifndef __UI_FACTORY_H__
#define __UI_FACTORY_H__

#include <iostream>
#include "UI_Factory.h"
#include "UIImpl.h"
#include "Passenger_UI_Impl.h"
#include "Crew_UI_Impl.h"
#include "Notifier.h"

class UIFactory {
public:
  UIFactory(Notifier& _n1){};
  ~UIFactory(){};

  static IUI* CreateUI(const std::string& Impl, Notifier& _n1)
  {
    IUI* ptrUI = 0;
      if (Impl == "Passenger")
      {
        ptrUI = new PassengerUIImpl(_n1);
				ptrUI->RunUI(_n1);
      }
      if (Impl == "Crew")
      {
        ptrUI = new CrewUIImpl(_n1);
				ptrUI->RunUI(_n1);
      }
    return ptrUI;
  };

};

#endif /* __UIFACTORY_H__ */
