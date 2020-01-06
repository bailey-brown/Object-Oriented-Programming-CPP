
CXXFLAGS += --std=c++17

main: main.o Vehicle.o Gas_vehicle.o Electric_vehicle.o
	${CXX} ${CXXFLAGS} -o vehicle main.o Vehicle.o Gas_vehicle.o Electric_vehicle.o
	
main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp

Vehicle.o: Vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c Vehicle.cpp

Gas_vehicle.o: Gas_vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c Gas_vehicle.cpp

Electric_vehicle.o: Electric_vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c Electric_vehicle.cpp

clean:
	-rm -f *.o *.gch *~ a.out vehicle
