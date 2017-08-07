#include <iostream>
#include <cstdlib>
#include "UIImpl.h"
#include "Crew_UI_Impl.h"
#include "FlightInfo.h"

/* ------------------------------------------------------------- */

void CrewUIImpl::RunUI(Notifier& n1)
{
  int userChoice, ret;
	ret = InitialRun(n1);
	if (ret == 2)
	{
		return;
	}

  do
  {
    long passID, deleteBooking;
    std::string flightID;
    int userDecision;
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1.  Get all ELעלALאל flights" << std::endl;
    std::cout << "2.  Search flights" << std::endl;
    std::cout << "3.  Create a new flight" << std::endl;
    std::cout << "4.  Update a flight" << std::endl;
    std::cout << "5.  Cancel a flight" << std::endl;
    std::cout << "6.  Get all bookings for a flight" << std::endl;
    std::cout << "7.  Get all bookings for a passenger" << std::endl;
    std::cout << "8.  See all current ELעלALאל passsengers" << std::endl;
    std::cout << "9.  Book a passenger on a flight" << std::endl;
    std::cout << "10. Delete a booking" << std::endl;
    std::cout << "11. Go back to the previous menu" << std::endl;
    std::cin  >> userChoice;

    switch (userChoice)
    {
      case 1:
        std::cout << "ALL CURRENT ELעלALאל FLIGHTS" << std::endl;
        n1.GetAllCurrentFlight();
        break;

      case 2:
        n1.FilterFlights();
        break;

      case 3:
        system("clear");
        CreateNewFlight(n1);
        break;

      case 4:
        system("clear");
        UpdateExistingFlight(n1);
        break;

      case 5:
        std::cout << "Please insert the ID of the flight you'd like to cancel: " << std::endl;
        std::cin >> flightID;
        n1.NotifyDeleteFlight(flightID);
        break;

      case 6:
        system("clear");
        std::cout << "Please insert the flight ID number: " << std::endl;
        std::cin >> flightID;
        n1.GetAllBookingsByFlight(flightID);
        break;

      case 7:
        system("clear");
        std::cout << "Please insert the passenger's ID number: " << std::endl;
        std::cin >> passID;
        n1.GetAllBookingsByPassenger(passID);
        break;

      case 8:
        n1.GetAllCurrentPassengers();
        break;

      case 9:
        BookFlight(n1);
        break;

      case 10:
        n1.GetAllBookings();
        std::cout << "Please insert the booking ID to delete be deleted: " << std::endl;
        std::cin >> deleteBooking;
        n1.NotifyDeleteBooking(deleteBooking);
        std::cout << "We're sorry to see you go!" << std::endl;
        break;

      case 11:
        system("clear");
        break;

      default:
        break;
    }
  } while(userChoice != 11);
}

/* ------------------------------------------------------------- */

int CrewUIImpl::InitialRun(Notifier& n1)
{
  int userChoice;
  long userID, userPhone;
  std::string userName, userAddress;
  std::cout << "Welcome back to ELעלALאל! Please input your worker ID number" << std::endl;
  std::cout << "Click 2 to exit" << std::endl;
  std::cin  >> userChoice;
  if (userChoice == 2)
  {
    std::cout << "Goodbye..." << std::endl;
    return userChoice;
  }
  system("clear");
	return userChoice;
}

/* ------------------------------------------------------------- */

void CrewUIImpl::BookFlight(Notifier& _n1)
{
  std::string flightID, priority;
  int userChoice;
  long passID;
  std::string userSeat;
  std::cout << "Please insert the passenger's ID number: " << std::endl;
  std::cin >> passID;
  std::cout << "Please insert the flight ID number: " << std::endl;
  std::cin >> flightID;
  std::cout << "Would the passenger like to see the available seating?: (1) yes (2) no " << std::endl;
  std::cin >> userChoice;

  if (userChoice == 1)
  {
    std::cout << "Getting passenger's seating arrangement" << std::endl;
    _n1.GetSeatingChart(flightID, flightID);
  }
  std::cout << "Is there a specific seat they would like?: (1) yes (2) no " << std::endl;
  std::cin >> userChoice;

  if (userChoice == 1)
  {
    std::cout << "Please first input the class: (1) First Class (2) Economy Class " << std::endl;
    std::cin >> userChoice;
    std::cout << "Now please input the seat the passenger would like: " << std::endl;
    std::cin >> userSeat;
    priority = (userChoice == 1) ? "Priority" : "Economy";
    _n1.NotifyNewBooking(passID, flightID, userSeat, priority, false);
  }

  else if (userChoice == 2)
  {
    std::cout << "Please input the class they would like: (1) First Class (2) Economy Class " << std::endl;
    std::cin >> userChoice;
    priority = (userChoice == 1) ? "Priority" : "Economy";
    userSeat = "";
    _n1.NotifyNewBooking(passID, flightID, userSeat,  priority, false);
  }
}

/* ------------------------------------------------------------- */

void CrewUIImpl::CreateNewFlight(Notifier& n1)
{
  FlightInfo newFlight;
  std::string date, flightID, destination, departure;
  size_t planeType;
  float flightTime, price;
  std::string pT1 = "Airbus A340-300";
  std::string pT2 = "Airbus A340-500";
  std::string pT3 = "Boeing 777-200";
  std::string pT4 = "Boeing 777-300";
  std::string pT5 = "Boeing 747-400";

  std::cout << "Please input the new flight's ID: " << std::endl;
  std::cin >> flightID;
  newFlight.m_flightID = flightID;

  std::cout << "Please input the new flight's time: " << std::endl;
  std::cin >> flightTime;
  newFlight.m_flightTime = flightTime;

  std::cout << "Please input the new flight's destination: " << std::endl;
  std::cin >> destination;
  newFlight.m_destination = destination;

  std::cout << "Please input the new flight's departure: " << std::endl;
  std::cin >> departure;
  newFlight.m_departure = departure;

  std::cout << "What type of plane is it?" << std::endl;
  std::cout << "1. " << pT1 << std::endl;
  std::cout << "2. " << pT2 << std::endl;
  std::cout << "3. " << pT3 << std::endl;
  std::cout << "4. " << pT4 << std::endl;
  std::cout << "5. " << pT5 << std::endl;
  std::cin >> planeType;
  switch (planeType)
  {
    case 1:
      newFlight.m_planeType = pT1;
      break;

    case 2:
      newFlight.m_planeType = pT2;
      break;

    case 3:
      newFlight.m_planeType = pT3;
      break;

    case 4:
      newFlight.m_planeType = pT4;
      break;

    case 5:
      newFlight.m_planeType = pT5;
      break;

    default:
      break;
  }
  std::cout << "Please input the new flight's price: " << std::endl;
  std::cin >> price;
  newFlight.m_price = price;

  std::cout << "Please input the new flight's date: " << std::endl;
  std::cin >> date;
  newFlight.m_date = date;

  n1.NotifyNewFlight(newFlight);
}

/* ------------------------------------------------------------- */

void CrewUIImpl::UpdateExistingFlight(Notifier& n1)
{
  std::string flightID;
  int userChange;
  std::cout << "Please input the existing flight's ID: " << std::endl;
  std::cin >> flightID;
  std::cout << "Here's the flight's current information:" << std::endl;
  n1.GetFlightInfo(flightID);
  std::cout << "What would you like to change?" << std::endl;
  std::cout << "1. Time" << std::endl;
  std::cout << "2. Destination" << std::endl;
  std::cout << "3. Price" << std::endl;
  std::cin >> userChange;
  CreateChange(n1, userChange, flightID);
}

/* ------------------------------------------------------------- */

void CrewUIImpl::CreateChange(Notifier& n1, int userChange, std::string& flightID)
{
  float newTimeOrPrice;
  std::string newDestination;
  size_t newCapacity;
  std::string time = "Time";
  std::string dest = "Destination";
  std::string price = "Price";

  switch(userChange)
  {
    case 1:
      std::cout << "Please insert the new flight time: " << std::endl;
      std::cin >> newTimeOrPrice;
      n1.NotifyFlightChange(time, flightID, newTimeOrPrice);
      break;

    case 2:
      std::cout << "Please insert the new flight destination: " << std::endl;
      std::cin >> newDestination;
      n1.NotifyFlightChange(dest, flightID, newDestination);
      break;

    case 3:
      std::cout << "Please insert the new flight price: " << std::endl;
      std::cin >> newTimeOrPrice;
      n1.NotifyFlightChange(price, flightID, newTimeOrPrice);
      break;

    default:
      break;
  }
}

/* ------------------------------------------------------------- */
