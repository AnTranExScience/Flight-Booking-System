#ifndef __PASSENGER_UI_IMPL_H__
#define __PASSENGER_UI_IMPL_H__

#include <iostream>

class UIImpl;
class Notifier;

class PassengerUIImpl : public IUI
{
public:
  PassengerUIImpl(Notifier& n1){};
  ~PassengerUIImpl(){};
  virtual void RunUI(Notifier& n1);

private:
  int InitialRun(Notifier& n1);
  void setPassId(long _id) {m_passengerID = _id;}
  long getPassId() {return m_passengerID;}
  void BookFlight(Notifier& _n1);
  void passengerUpdate(int userDecision, Notifier& n1);

  long m_passengerID;
};

#endif /* __PASSENGER_UI_IMPL_H__ */
