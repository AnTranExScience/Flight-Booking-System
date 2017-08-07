#include <string>
#include <iostream>
#include <cstdlib>

#include "StartUp.h"
#include "FlightsELAL.h"
#include "PassengersELAL.h"
#include "BookingsELAL.h"
#include "FlightInfo.h"
#include "Notifier.h"
#include "UI_Factory.h"

/* ------------------------------------------------------------- */

void StartUp::Run()
{
  Notifier& n1 = createNotifier();
  setFlights(n1);
  UIFactory u1(n1);
  UIType(u1, n1);
}

/* ------------------------------------------------------------- */

void StartUp::UIType(UIFactory u1, Notifier& n1)
{
  system("clear");
  int userType;
  std::cout << "             Welcome to ELעלALאל!            " << std::endl;
  std::cout << "Are you (1) a passenger or (2) a crew member?" << std::endl;
  std::cout << "                   (3) Exit                  " << std::endl;
  std::cin  >> userType;
  do{
    switch (userType)
    {
      case 1:
        u1.CreateUI("Passenger", n1);
        break;
      case 2:
        u1.CreateUI("Crew", n1);
        break;
			case 3:
        std::cout << "Goodbye..." << std::endl;
        break;
      default:
        std::cout << "You had one job. Try again." << std::endl;
        break;
    }
  }while(userType != 3);
}

/* ------------------------------------------------------------- */

Notifier& StartUp::createNotifier()
{
  PassengersELAL& pm1 = PassengersELAL::createObj();
  FlightsELAL& fm1 = FlightsELAL::createObj();
  BookingsELAL& bm1 = BookingsELAL::createObj();

  Notifier& s1 = Notifier::createObj();
  s1.setPointers(&pm1, &fm1, &bm1);
  return s1;
}

/* ------------------------------------------------------------- */

void StartUp::setFlights(Notifier& _s1)
{
  std::string A1 = "A1";
  std::string empty = "";
  std::string Priority = "Priority";
  std::string Economy = "Economy";

  long passengerID[20] = {2938047,      12390238,      123456,         438592,        8439754,          3292384,          498576,              867034,      10458354,   4539085,     459067,       6392474,     2345236,     623426,     75456467,    345636,       976868,      843452,      8656634,    34768456};
  std::string name[20] =      {"Tom Cruise", "Johnny Depp", "Hannah Baker", "Megan Hurta", "Angelina Jolie", "Justin Trudeau", "Drumpf the Cheeto", "Yuval",     "Tomer",    "Leore",     "Suha",       "Pavel",     "George",    "Guy",      "Vasili",    "Meir",       "Stacy",     "Yosi",      "Itzik",    "Igal"};
  std::string address[20] =   {"TPE",        "YYZ",         "TLV",          "CPH",         "TPE",            "TPE",            "YYZ",               "TLV",       "TRN",      "TRN",       "TPE",        "CPH",       "TLV",       "CPH",      "HOU",       "HOU",        "YYZ",       "YYZ",       "TRN",      "CPH"};
  long number[20] =      {54331,  753316,   10033,   6533,    123336,      1003323,     5433135,         54331,  753316,   10033,   6533,    123336,      1003323,     5433135,         124136, 1003123, 543316, 753316, 65313, 123316};

  for (int i = 0; i < 20; i++)
  {
    _s1.NotifyNewPassenger(name[i], address[i], passengerID[i], number[i]);
  }

  std::list<Flight> m_flights;
  std::string flightID[20]    = {"F1234",           "H7899",           "K9763",          "G2335",           "D8695",         "S1325",            "P0868",          "V1537",          "M0813",          "F9705",          "M9790",           "V0857",           "F1234",          "C0381",          "F1234",          "C8867",           "S8612",          "M8757",           "F1234",          "Z0987"};
  std::string destination[20] = {"YYZ",             "YYZ",             "TLV",            "TLV",             "CPH",           "CPH",              "TPE",            "TPE",            "YYZ",            "TLV",            "CPH",             "TPE",             "HOU",            "HOU",            "TRN",            "TRN",             "TRN",            "CPH",             "YYZ",            "TPE"};
  std::string departure[20]   = {"TLV",             "TPE",             "YYZ",            "CPH",             "TPE",           "TPE",              "YYZ",            "TLV",            "TRN",            "TRN",            "TPE",             "CPH",             "TLV",            "CPH",            "HOU",            "HOU",             "YYZ",            "YYZ",             "TRN",            "CPH"};
  std::string planeType[20]   = {"Airbus A340-300", "Airbus A340-500", "Boeing 777-200", "Boeing 777-300", "Boeing 747-400", "Airbus A340-300", "Airbus A340-500", "Boeing 777-200", "Boeing 777-300", "Boeing 747-400", "Airbus A340-300", "Airbus A340-500", "Boeing 777-200", "Boeing 777-300", "Boeing 747-400", "Airbus A340-300", "Airbus A340-500","Boeing 777-200", "Boeing 777-300", "Boeing 747-400"};
  float flightTime[20]   = {10.23,              5.45,              7.53,             6.53,             12.36,            15.23,             14.50,             17.03,            16.39,           34.59,            10.23,             23.59,             23.34,             20.3,            22.26,             10.38,            17.57,            4.38,             20.03,             12.36};
  float price[20]        = {100.23,             543.5,             753.3,            65.3,             123.6,            100.23,            543.5,             753.3,            65.3,            123.6,            100.23,            543.5,             753.3,             65.3,            123.6,             100.23,           543.5,            753.3,            65.3,              123.6};
  std::string date[20]        = {"01/20",            "02/29",           "03/06",          "04/08",          "05/24",          "06/30",           "07/21",           "08/02",          "07/30",         "08/17",          "09/20",           "10/12",          "11/11",          "12/12",        "01/01",           "02/28",          "03/03",          "04/04",          "05/05",           "06/06"};
  std::string seats[20]       = {"30E",              "28A",             "18B",            "20C",            "14D",            "17H",             "22G",             "15E",            "12A",           "22B",            "33C",             "13D",             "31E",             "19F",           "19G",             "13H",            "25A",            "34B",            "16C",             "25F"};
  std::string priSeats[20]    = {"3E",               "8A",              "8B",             "1C",              "4D",            "7H",              "2G",              "5E",             "2A",            "2B",             "7C",              "3B",              "9E",              "5F",            "9G",              "6H",             "5A",             "4H",             "6H",              "5F"};

  FlightInfo fi[20];

  for (int i = 0; i < 20; i++)
  {
    fi[i].m_flightID    = flightID[i];
    fi[i].m_flightTime  = flightTime[i];
    fi[i].m_destination = destination[i];
    fi[i].m_departure   = departure[i];
    fi[i].m_planeType   = planeType[i];
    fi[i].m_price       = price[i];
    fi[i].m_date        = date[i];
    _s1.NotifyNewFlight(fi[i]);
  }

  for (int i = 0; i < 20; i++)
  {
    _s1.NotifyNewBooking(passengerID[i], fi[i].m_flightID, seats[i], Economy, true);
  }

  for (int i = 0; i < 20; i++)
  {
    _s1.NotifyNewBooking(passengerID[i], fi[0].m_flightID, seats[i], Economy, true);
  }

  for (int i = 0; i < 19; i++)
  {
    _s1.NotifyNewBooking(passengerID[i], fi[i+1].m_flightID, priSeats[i], Priority, true);
  }

  for (int i = 1; i < 20; i++)
  {
    _s1.NotifyNewBooking(passengerID[i], fi[i-1].m_flightID, seats[i], Economy, true);
  }
}

/* ------------------------------------------------------------- */
