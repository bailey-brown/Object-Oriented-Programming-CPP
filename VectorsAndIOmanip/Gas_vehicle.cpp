
#include <string>
#include "gas_vehicle.h"


Gas_vehicle::Gas_vehicle(int year, std::string make, std::string model, Body_style body_style, double miles_per_gallon, double max_gallons)
				        : Vehicle(year, make, model, body_style), _miles_per_gallon{miles_per_gallon}, _max_gallons{max_gallons} { }
	  
double Gas_vehicle::gallons_consumed(double miles) {
	return miles / _miles_per_gallon;
}


