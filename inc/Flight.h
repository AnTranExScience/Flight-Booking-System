#ifndef __FLIGHT_H__
#define __FLIGHT_H__

#include "SeatsELAL.h"
#include "Seat.h"
#include "FlightInfo.h"

class Booking;

class Flight
{
public:
  explicit Flight(FlightInfo _fi);
  Flight(const Flight& _existingFlight);
  ~Flight(){};

  inline const std::string  getDeparture() const;
  inline const std::string  getDestination() const;
  inline std::string        getFlightID() const;
  inline float              getFlightDepartTime() const;
  inline size_t             getSeatCapacity() const;
  inline float              getPrice() const;
  inline std::string        getDate() const;

  void   printInfo() const;
  void   printEconomySeats();
  void   printFirstClassSeats();
  void   printAllSeats();
  size_t getAvailableEconomySeats() const;
  size_t getAvailableFirstClassSeats() const;
  void   getPlaneCapacity() const;
  PassengerFlightInfo getFlightInfo() const;
  //std::list<std::string>& getFlightList() const;

  inline void updateDestination(const std::string& _s);
  inline void updateSeatCapacity(size_t _t);
  void update(std::string& _type, float _f);

  inline const std::string AssignRandomEconomySeat(bool _shouldPrint);
  inline const std::string AssignRandomFirstClassSeat(bool _shouldPrint);
  inline std::string GetDefaultPlaneType() const;
  inline std::string GetPlaneType() const;
  inline void SetDefaultPlaneType(std::string& _plane);
  inline void SetPlaneType(std::string& _plane);
  inline void setSeatAvailable(std::string _seat, std::string _priority);
  inline bool AssignRequestedSeat(const std::string& _seat, const std::string& _priority, bool _shouldPrint);

private:
  SeatsELAL   m_sm;
  std::string m_flightID;
  float       m_flightTime;
  std::string m_destination;
  std::string m_departure;
  std::string m_planeType;
  size_t      m_capacity;
  float       m_price;
  std::string m_date;

  Flight&  operator=(const Flight& _existingFlight);
};

inline const std::string Flight::getDeparture() const        {return m_departure;}
inline const std::string Flight::getDestination() const      {return m_destination;}
inline std::string Flight::GetDefaultPlaneType() const       {return m_sm.GetDefaultPlaneType();}
inline std::string Flight::GetPlaneType() const              {return m_sm.GetPlaneType();}
inline std::string Flight::getFlightID() const               {return m_flightID;}
inline std::string Flight::getDate() const                   {return m_date;}
inline float  Flight::getFlightDepartTime() const            {return m_flightTime;}
inline size_t Flight::getSeatCapacity() const                {return m_capacity;}
inline float  Flight::getPrice() const                       {return m_price;}
inline void Flight::SetDefaultPlaneType(std::string& _plane) {return m_sm.SetDefaultPlaneType(_plane);}
inline void Flight::SetPlaneType(std::string& _plane)        {return m_sm.SetPlaneType(_plane);}
inline void Flight::updateDestination(const std::string& _s) {m_destination = _s;}
inline void Flight::updateSeatCapacity(size_t _t)            {m_capacity = _t;}
inline void Flight::setSeatAvailable(std::string _seat, std::string _priority) {return m_sm.setSeatAvailable(_seat, _priority);}
inline const std::string Flight::AssignRandomEconomySeat(bool _shouldPrint)    {return m_sm.AssignRandomEconomySeat(_shouldPrint);}
inline const std::string Flight::AssignRandomFirstClassSeat(bool _shouldPrint) {return m_sm.AssignRandomFirstClassSeat(_shouldPrint);}
inline bool Flight::AssignRequestedSeat(const std::string& _seat, const std::string& _priority, bool _shouldPrint) {return m_sm.AssignRequestedSeat(_seat, _priority, _shouldPrint);}

#endif /* __FLIGHT_H__ */


//enter a function, static, ipc, projects, race condition, put into a list without sentinels (why need sentinels?)
