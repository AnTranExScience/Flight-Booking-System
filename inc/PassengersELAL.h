#ifndef __PASSENGERSELAL_H__
#define __PASSENGERSELAL_H__

#include <list>
#include "Passenger.h"

class PassengersELAL
{
public:
  static PassengersELAL& createObj() {return pm;}
  void createNewPassenger(std::string& _name, std::string& _add, long _id, long _ph);
  void deleteExistingPassenger(long _id);
  void printAllPassengers() const;
  void printPassenger(long _passengerID);
  void updateAddress(long _id, std::string _s);
  void updateName(long _id, std::string _s);
  void updateNumber(long _id, long _l);

private:
  static PassengersELAL pm;
  std::list<Passenger*> m_passengers;

  std::list<Passenger*>::iterator returnIterator(long _id);
  PassengersELAL(){}
  ~PassengersELAL();
  PassengersELAL(const PassengersELAL&);
  void operator=(PassengersELAL&);
};

#endif /* __PASSENGERSELAL_H__ */
