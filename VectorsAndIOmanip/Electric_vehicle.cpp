

#include <string>
#include "electric_vehicle.h"

Electric_vehicle::Electric_vehicle(int year, std::string make, std::string model, Body_style body_style, double miles_per_kwh, double max_kwh)
				: Vehicle(year, make, model, body_style), _miles_per_kwh{miles_per_kwh}, _max_kwh{max_kwh} { }
	  
double Electric_vehicle::kwh_consumed(double miles)
{
	return miles / _miles_per_kwh;
}

