#ifndef __BOOKING_H__
#define __BOOKING_H__

#include "FlightInfo.h"

class Booking
{
  public:
    Booking(long _bookingID, long _passengerID, PassengerFlightInfo _pfi, std::string& _seat, std::string& _priority);
    Booking(const Booking& _existingBooking);
    ~Booking(){};

    bool addSeatSelection();
    void deleteSeatSelection();
    bool updateSeatSelection();

    inline const std::string  getFlightID()       const;
    inline const std::string  getDeparture()      const;
    inline const std::string  getDestination()    const;
    inline const std::string  getDate()           const;
    inline const std::string  getSeatAssignment() const;
    inline const std::string  getPriority()       const;
    inline const long  getBookingID()             const;
    inline long        getPassengerID()           const;
    inline float       getBookingDepartTime()     const;
    inline float       getPrice()                 const;
    void        printInfo()   const;
    void        updateBooking(const std::string _type, std::string& _change); //dest,seat,priority
    void        updateBooking(const std::string _type, float _change);        //time,price

  private:
    const std::string m_flightID;
    const long        m_passengerID;
    const long        m_bookingID;
    std::string       m_destination;
    std::string       m_departure;
    std::string       m_seatAssignment;
    std::string       m_priority;
    std::string       m_date;
    float             m_flightTime;
    float             m_price;

    Booking&  operator=(const Booking& _existingBooking);
  };

inline const std::string  Booking::getFlightID()       const {return m_flightID;}
inline const std::string  Booking::getDeparture()      const {return m_departure;}
inline const std::string  Booking::getDestination()    const {return m_destination;}
inline const std::string  Booking::getDate()           const {return m_date;}
inline const std::string  Booking::getSeatAssignment() const {return m_seatAssignment;}
inline const std::string  Booking::getPriority()       const {return m_priority;}
inline const long  Booking::getBookingID()             const {return m_bookingID;}
inline long        Booking::getPassengerID()           const {return m_passengerID;}
inline float       Booking::getBookingDepartTime()     const {return m_flightTime;}
inline float       Booking::getPrice()                 const {return m_price;}


#endif /* __BOOKING_H__ */


//enter a function, static, ipc, projects, race condition, put into a list without sentinels (why need sentinels?)
