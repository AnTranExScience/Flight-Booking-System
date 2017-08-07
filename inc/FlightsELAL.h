#ifndef __FLIGHTSELAL_H__
#define __FLIGHTSELAL_H__

#include <list>
#include "Flight.h"

class FlightInfo;

class FlightsELAL
{
public:
  inline static FlightsELAL& createObj() {return pm;}
  void createNewFlight(FlightInfo _pfi);
  void deleteExistingFlight(std::string& _id);

  void printAllFlights() const;
  void printFlightInfo(std::string& _id);
  void printEconomySeats(std::string& _id);
  void printFirstClassSeats(std::string& _id);
  void printAllSeats(std::string& _id);

  void updateSeatCapacity(std::string& _id, size_t _t);
  void updateDestination(std::string& _id, std::string& _s);
  void update(std::string& _type, std::string& _id, float _l);

  bool  isFlightIDUnique(const std::string& _newID) const;
  float GetPrice(std::string& _id);

  std::string GetDate(std::string& _id);
  std::string GetDefaultPlaneType(std::string& _id);
  std::string GetPlaneType(std::string& _id);
  std::string AssignRandomEconomySeat(std::string& _id, bool _shouldPrint);
  std::string AssignRandomFirstClassSeat(std::string& _id, bool _shouldPrint);
  PassengerFlightInfo getFlightInfo(const std::string& _flightID);
  inline std::list<Flight*>& GetListOfFlights();

  void SetSeatAvailable(std::string& _flightID, std::string& _seatAssignment, std::string& _priority);
  bool AssignRequestedSeat(std::string& _id, const std::string& _seat, const std::string& _priority, bool _shouldPrint);
  void SetDefaultPlaneType(std::string& _id, std::string& _plane);
  void SetPlaneType(std::string& _id, std::string& _plane);

private:
  static FlightsELAL pm;
  std::list<Flight*>  m_Flights;

  FlightsELAL(){}
  inline ~FlightsELAL();
  std::list<Flight*>::iterator returnIterator(std::string& _id);
  FlightsELAL(const FlightsELAL&);
  void operator=(FlightsELAL&);
};

inline std::list<Flight*>& FlightsELAL::GetListOfFlights() {return m_Flights;}

inline FlightsELAL::~FlightsELAL()
{
  std::list<Flight*>::iterator it;
  for (it = m_Flights.begin(); it != m_Flights.end(); it++)
  {
    delete *it;
    m_Flights.erase(it);
  }
};

#endif /* __FLIGHTSELAL_H__ */
