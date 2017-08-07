CXX = g++
CXXFLAGS = -c -I ./inc/
LINKERFLAGS = -I ./inc/

SRCP = ./src/
INCP = ./inc/
OBJP = ./objects/

SRCS = $(SRCP)Booking.cpp $(SRCP)BookingsELAL.cpp $(SRCP)Crew_UI_Impl.cpp $(SRCP)Date_Filter_Impl.cpp $(SRCP)Departure_Filter_Impl.cpp $(SRCP)Destination_Filter_Impl.cpp $(SRCP)FilterImpl.cpp $(SRCP)Flight.cpp $(SRCP)FlightsELAL.cpp $(SRCP)Notifier.cpp $(SRCP)Passenger_UI_Impl.cpp $(SRCP)Passenger.cpp $(SRCP)PassengersELAL.cpp $(SRCP)Price_Filter_Impl.cpp $(SRCP)SeatsELAL.cpp $(SRCP)UIImpl.cpp $(SRCP)StartUp.cpp
INCS = $(INCP)Booking.h $(INCP)BookingsELAL.h $(INCP)Crew_UI_Impl.h $(INCP)Date_Filter_Impl.h $(INCP)Departure_Filter_Impl.h $(INCP)Destination_Filter_Impl.h $(INCP)Filter_Factory.h $(INCP)FilterImpl.h $(INCP)Flight.h $(INCP)FlightInfo.h $(INCP)FlightsELAL.h $(INCP)Notifier.h $(INCP)Passenger_UI_Impl.h $(INCP)Passenger.h $(INCP)PassengersELAL.h $(INCP)Price_Filter_Impl.h $(INCP)SeatsELAL.h $(INCP)UI_Factory.h $(INCP)UIImpl.h $(INCP)Seat.h $(INCP)StartUp.h

OBJS = $(OBJP)Booking.o $(OBJP)BookingsELAL.o $(OBJP)Crew_UI_Impl.o $(OBJP)Date_Filter_Impl.o $(OBJP)Departure_Filter_Impl.o $(OBJP)Destination_Filter_Impl.o $(OBJP)FilterImpl.o $(OBJP)Flight.o $(OBJP)FlightsELAL.o $(OBJP)Notifier.o $(OBJP)Passenger_UI_Impl.o $(OBJP)Passenger.o $(OBJP)PassengersELAL.o $(OBJP)Price_Filter_Impl.o $(OBJP)SeatsELAL.o $(OBJP)UIImpl.o $(OBJP)StartUp.o

runner: $(OBJS) $(SRCP)main.cpp
	$(CXX) $(LINKERFLAGS) -o runner $(OBJS) $(SRCP)main.cpp

$(OBJP)Booking.o : $(SRCP)Booking.cpp $(INCP)Booking.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Booking.o $(SRCP)Booking.cpp

$(OBJP)BookingsELAL.o : $(SRCP)BookingsELAL.cpp $(INCP)BookingsELAL.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)BookingsELAL.o $(SRCP)BookingsELAL.cpp

$(OBJP)Crew_UI_Impl.o : $(SRCP)Crew_UI_Impl.cpp $(INCP)Crew_UI_Impl.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Crew_UI_Impl.o $(SRCP)Crew_UI_Impl.cpp

$(OBJP)Date_Filter_Impl.o : $(SRCP)Date_Filter_Impl.cpp $(INCP)Date_Filter_Impl.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Date_Filter_Impl.o $(SRCP)Date_Filter_Impl.cpp

$(OBJP)Departure_Filter_Impl.o : $(SRCP)Departure_Filter_Impl.cpp $(INCP)Departure_Filter_Impl.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Departure_Filter_Impl.o $(SRCP)Departure_Filter_Impl.cpp

$(OBJP)Destination_Filter_Impl.o : $(SRCP)Destination_Filter_Impl.cpp $(INCP)Destination_Filter_Impl.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Destination_Filter_Impl.o $(SRCP)Destination_Filter_Impl.cpp

$(OBJP)FilterImpl.o : $(SRCP)FilterImpl.cpp $(INCP)FilterImpl.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)FilterImpl.o $(SRCP)FilterImpl.cpp

$(OBJP)Flight.o : $(SRCP)Flight.cpp $(INCP)Flight.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Flight.o $(SRCP)Flight.cpp

$(OBJP)FlightsELAL.o : $(SRCP)FlightsELAL.cpp $(INCP)FlightsELAL.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)FlightsELAL.o $(SRCP)FlightsELAL.cpp

$(OBJP)Notifier.o : $(SRCP)Notifier.cpp $(INCP)Notifier.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Notifier.o $(SRCP)Notifier.cpp

$(OBJP)Passenger_UI_Impl.o : $(SRCP)Passenger_UI_Impl.cpp $(INCP)Passenger_UI_Impl.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Passenger_UI_Impl.o $(SRCP)Passenger_UI_Impl.cpp

$(OBJP)Passenger.o : $(SRCP)Passenger.cpp $(INCP)Passenger.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Passenger.o $(SRCP)Passenger.cpp

$(OBJP)PassengersELAL.o : $(SRCP)PassengersELAL.cpp $(INCP)PassengersELAL.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)PassengersELAL.o $(SRCP)PassengersELAL.cpp

$(OBJP)Price_Filter_Impl.o : $(SRCP)Price_Filter_Impl.cpp $(INCP)Price_Filter_Impl.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)Price_Filter_Impl.o $(SRCP)Price_Filter_Impl.cpp

$(OBJP)SeatsELAL.o : $(SRCP)SeatsELAL.cpp $(INCP)SeatsELAL.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)SeatsELAL.o $(SRCP)SeatsELAL.cpp

$(OBJP)UIImpl.o : $(SRCP)UIImpl.cpp $(INCP)UIImpl.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)UIImpl.o $(SRCP)UIImpl.cpp

$(OBJP)StartUp.o : $(SRCP)StartUp.cpp $(INCP)StartUp.h
	$(CXX) $(CXXFLAGS) -o $(OBJP)StartUp.o $(SRCP)StartUp.cpp

clean:
	rm -f $(OBJP)*.o ./runner

run:
	make clean
	make runner
	./runner

rebuild:
	make clean
	make run
