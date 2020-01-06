
#include <iostream>
#include <string>
#include <map>
#include "vehicle.h"


Vehicle::Vehicle(int year, std::string make, std::string model, Body_style body_style) 
				: _year{year}, _make{make}, _model{model}, _body_style{body_style} { }
			  
std::string Vehicle::make() {return _make;} 
std::string Vehicle::model() {return _model;} 
int Vehicle::year() {return _year;}
Body_style Vehicle::body_style() {return _body_style;}

std::string Vehicle::body_style_to_string() const
{
	std::map<Body_style, std::string> body_style_string = 
	{
		{Body_style::SEDAN, "Sedan"},
		{Body_style::HATCHBACK, "Hatchback"},
		{Body_style::SUV, "SUV"}
	};
	
	return body_style_string[_body_style];
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) 
{  
	  os << vehicle._year << " " << vehicle._make << " " << vehicle._model << " " << vehicle.body_style_to_string();	  
	  return os; 
}

    