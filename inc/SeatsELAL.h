#ifndef __SEATSELAL_H__
#define __SEATSELAL_H__

#include <list>
#include <string>

class Seat;

class SeatsELAL
{
public:
  SeatsELAL();
  ~SeatsELAL(){};
  inline std::string GetDefaultPlaneType() const;
  inline std::string GetPlaneType() const;
  inline void        SetDefaultPlaneType(std::string& _plane);
  void               SetPlaneType(std::string& _plane);

  inline size_t GetPlaneCapacity() const;
  inline size_t GetAvailableFirstClassSeats() const;
  inline size_t GetAvailableEconomySeats() const;

  void              setSeatAvailable(std::string _seat, std::string _priority);
  bool              AssignRequestedSeat(const std::string& _seat, const std::string& _priority, bool _isStartUp);
  const std::string AssignRandomEconomySeat(bool _isStartUp);
  const std::string AssignRandomFirstClassSeat(bool _isStartUp);

  void PrintAvaliableEconomySeats();
  void PrintAvaliableFirstClassSeats();

private:
  void setAvailableEconomySeats(size_t _totalSeats);
  std::string GetRandomSeat(std::string _type);
  void setPlaneInfo();
  void setAvailableFirstClassSeats();
  void setAvailableSeats(size_t _totalSeats);
  std::list<Seat>::iterator getFirstClassIterator(std:: string _seat);
  std::list<Seat>::iterator getEconomyClassIterator(std:: string _seat);

  static std::string m_defaultPlaneType;
  std::list<Seat>    m_firstClass;
  std::list<Seat>    m_economyClass;
  std::string        m_planeType;
  size_t             m_capacity;
  size_t             m_availableEconomySeats;
  size_t             m_availableFirstClassSeats;
  size_t             m_totalSeatsAvailable;

  SeatsELAL(const SeatsELAL& _seatsELAL);
  SeatsELAL& operator=(const SeatsELAL& _seatsELAL);
};

inline std::string SeatsELAL::GetDefaultPlaneType() const        {return m_defaultPlaneType;}
inline std::string SeatsELAL::GetPlaneType() const               {return m_planeType;}
inline size_t SeatsELAL::GetPlaneCapacity() const                {return m_capacity;}
inline size_t SeatsELAL::GetAvailableFirstClassSeats() const     {return m_availableFirstClassSeats;}
inline size_t SeatsELAL::GetAvailableEconomySeats() const        {return m_availableEconomySeats;}
inline void   SeatsELAL::SetDefaultPlaneType(std::string& _plane){m_defaultPlaneType = _plane;}

#endif /* __SEATSELAL_H__ */
