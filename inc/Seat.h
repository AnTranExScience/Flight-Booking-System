#ifndef __SEAT_H__
#define __SEAT_H__

class Seat
{
public:
  Seat(std::string _s):m_isAvailable(true), m_name(_s){};
  Seat(const Seat& _seat):m_isAvailable(_seat.m_isAvailable), m_name(_seat.m_name){};

  ~Seat(){};
  inline std::string getSeatName() const;
  inline bool isAvailable() const;
  inline void setAvailable();
  inline void setUnavailable();
  inline void setSeatName(std::string _name);

private:
  std::string m_name;
  bool        m_isAvailable;

  Seat& operator=(const Seat& _seat);
};

inline std::string Seat::getSeatName() const             {return m_name;}
inline bool        Seat::isAvailable() const             {return m_isAvailable;}
inline void        Seat::setAvailable()                  {m_isAvailable = true;}
inline void        Seat::setUnavailable()                {m_isAvailable = false;}
inline void        Seat::setSeatName(std::string _name)  {m_name = _name;}

#endif /* __SEAT_H__ */
