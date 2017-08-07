#ifndef __STARTUP_H__
#define __STARTUP_H__

#include "UI_Factory.h"
class Notifier;

class StartUp
{
public:
  StartUp(){};
  ~StartUp(){};
  void Run();

private:
  void UIType(UIFactory u1, Notifier& n1);
  Notifier& createNotifier();
  void setFlights(Notifier& _s1);

  StartUp(const StartUp& _exSU);
  StartUp& operator=(const StartUp& _exSU);
};

#endif /* __STARTUP_H__ */
