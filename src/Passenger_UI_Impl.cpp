#include <iostream>
#include <cstdlib>
#include "UIImpl.h"
#include "Passenger_UI_Impl.h"

/* ------------------------------------------------------------- */

void PassengerUIImpl::RunUI(Notifier& n1)
{
	int ret = InitialRun(n1);
	if (ret == 3)
	{
		return;
	}

  int userChoice, userDecision;
  long newBooking, deleteBooking;
  do
  {
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Get all ELעלALאל flights" << std::endl;
    std::cout << "2. Get my info" << std::endl;
    std::cout << "3. Search flights" << std::endl;
    std::cout << "4. Get my bookings" << std::endl;
    std::cout << "5. Change my address, name, or number" << std::endl;
    std::cout << "6. Book a flight using flight ID" << std::endl;
    std::cout << "7. Cancel one of my bookings" << std::endl;
    std::cout << "8. Go back to the previous menu" << std::endl;
    std::cin  >> userChoice;

    switch (userChoice)
    {
      case 1:
        std::cout << "ALL CURRENT ELעלALאל FLIGHTS" << std::endl;
        n1.GetAllCurrentFlight();
        break;
      case 2:
        system("clear");
       	std::cout << "Your current profile: " << std::endl; 
			 	n1.GetInfoByPassenger(getPassId()); 
        break;
      case 3:
        n1.FilterFlights();
        break;
      case 4:
        system("clear");
        n1.GetAllBookingsByPassenger(getPassId());
        break;
      case 5:
        system("clear");
        std::cout << "What would you like to change?" << std::endl;
        std::cout << "1. Name" << std::endl;
        std::cout << "2. Address" << std::endl;
        std::cout << "3. Number" << std::endl;
        std::cout << "4. Back to the previous menu" << std::endl;
        std::cin >> userDecision;
        passengerUpdate(userDecision, n1);
        break;
      case 6:
        BookFlight(n1);
        break;
      case 7:
        n1.GetAllBookingsByPassenger(getPassId());
        std::cout << "Please insert the booking ID of the one you'd like to delete: " << std::endl;
        std::cin >> deleteBooking;
        n1.NotifyDeleteBooking(deleteBooking);
        std::cout << "We're sorry to see you go!" << std::endl;
        break;
      case 8:
        system("clear");
        break;
      default:
        break;
      }
    } while(userChoice != 8);
}

/* ------------------------------------------------------------- */

void PassengerUIImpl::passengerUpdate(int userDecision, Notifier& n1)
{
  long newNum;
  std::string newName, newAddress;
  std::string sName = "Name";
  std::string sAddress = "Address";
  switch(userDecision)
  {
    case 1:
      std::cout << "New name: " << std::endl;
      std::cin >> newName;
      n1.NotifyPassengerChange(sName, getPassId(), newName);
      break;
    case 2:
      std::cout << "New address: " << std::endl;
      std::cin >> newAddress;
      n1.NotifyPassengerChange(sAddress, getPassId(), newAddress);
      break;
    case 3:
      std::cout << "New number: " << std::endl;
      std::cin >> newNum;
      n1.NotifyPassengerNumberChange(getPassId(), newNum);
      break;
    default:
      break;
  }
  return;
}

/* ------------------------------------------------------------- */

int PassengerUIImpl::InitialRun(Notifier& n1)
{
  int userChoice;
  long userID, userPhone;
  std::string userName, userAddress;
  std::cout << "Would you like to create your profile, or do you have one?" << std::endl;
  std::cout << "1. I'd like to create a new profile" << std::endl;
  std::cout << "2. I have an account already" << std::endl;
  std::cout << "3. Exit" << std::endl;
  std::cin  >> userChoice;
  system("clear");

  switch (userChoice)
  {
    case 1:
      std::cout << "Welcome To ELעלALאל!" << std::endl << "Please provide your ID number:" << std::endl;
      std::cin >> userID;
      setPassId(userID);
      std::cout << "Please provide your name:" << std::endl;
      std::cin >> userName;
      std::cout << "Please provide your phone number:" << std::endl;
      std::cin >> userPhone;
      std::cout << "Please provide your address:" << std::endl;
      std::cin >> userAddress;
      n1.NotifyNewPassenger(userName, userAddress, userID, userPhone);
      break;
    case 2:
      std::cout << "Please provide your ID number:" << std::endl;
      std::cin >> userID;
      setPassId(userID);
      std::cout << "Welcome back!" << std::endl;
      break;
    case 3:
      system("clear");
      std::cout << "Goodbye..." << std::endl;
      break;
    default:
      break;
  }
	return userChoice;
}

/* ------------------------------------------------------------- */

void PassengerUIImpl::BookFlight(Notifier& _n1)
{
  std::string flightID, priority;
  int userChoice;
  std::string userSeat;
  std::cout << "Please enter the ID of the flight you'd like to book: " << std::endl;
  std::cin >> flightID;
  std::cout << "Would you like to see the available seating?: (1) yes (2) no " << std::endl;
  std::cin >> userChoice;
  if (userChoice == 1)
  {
    _n1.GetSeatingChart(flightID, flightID);
  }
  std::cout << "Is there a specific seat you'd like?: (1) yes (2) no " << std::endl;
  std::cin >> userChoice;
  if (userChoice == 1)
  {
    std::cout << "Please first input the class: (1) First Class (2) Economy Class " << std::endl;
    std::cin >> userChoice;
    std::cout << "Now please input the seat you'd like: " << std::endl;
    std::cin >> userSeat;
    priority = (userChoice == 1) ? "Priority" : "Economy";
    _n1.NotifyNewBooking(getPassId(), flightID, userSeat, priority, false);
  }
  else if (userChoice == 2)
  {
    std::cout << "Please input the class you'd like: (1) First Class (2) Economy Class " << std::endl;
    std::cin >> userChoice;
    priority = (userChoice == 1) ? "Priority" : "Economy";
    userSeat = "";
    _n1.NotifyNewBooking(getPassId(), flightID, userSeat, priority, false);
  }
}

/* ------------------------------------------------------------- */
