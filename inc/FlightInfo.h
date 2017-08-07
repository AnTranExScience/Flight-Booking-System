#ifndef __FLIGHT_INFO_H__
#define __FLIGHT_INFO_H__

struct FlightInfo
{
  std::string m_flightID;
  float       m_flightTime;
  std::string m_destination;
  std::string m_departure;
  std::string m_planeType;
  float       m_price;
  std::string m_date;
};

struct PassengerFlightInfo
{
  std::string m_flightID;
  float       m_flightTime;
  std::string m_destination;
  std::string m_departure;
  std::string m_seatAssignment;
  std::string m_priority;
  std::string m_planeType;
  float       m_price;
  std::string m_date;
};

#endif /* __FLIGHT_INFO_H__ */
