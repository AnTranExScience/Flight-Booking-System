#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <map>
#include <string>

class Passenger
{
public:
  Passenger(std::string& _name, std::string& _add, long _id, long _ph):m_name(_name), m_address(_add), m_ID(_id), m_number(_ph){};
  Passenger(const Passenger& _existingPassenger);
 ~Passenger(){};

  const std::string getName() const   {return m_name;}
  const std::string getAddress() const{return m_address;}
  long  getNumber() const             {return m_number;}
  long  getID() const                 {return m_ID;}
  void  printInfo() const;

  void  updateAddress(std::string _s) {m_address = _s;}
  void  updateName(std::string _s)    {m_name = _s;}
  void  updateNumber(long _l)         {m_number = _l;}

private:
  const long  m_ID;
  long        m_number;
  std::string m_name;
  std::string m_address;

  Passenger&  operator=(const Passenger& _existingPassenger);
};

#endif /* __PASSENGER_H__ */

