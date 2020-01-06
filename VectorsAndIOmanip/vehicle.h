
#ifndef __VEHICLE_H
#define __VEHICLE_H

#include <iostream>
#include <string> 
#include <vector>

enum class Body_style {SEDAN, HATCHBACK, SUV};

class Vehicle {
	public:
	  Vehicle(int year, std::string make, std::string model, Body_style body_style);
	  std:: string make();
	  std::string model();
	  int year();
	  Body_style body_style();
	  std::string body_style_to_string () const;
	  friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
	  
	private:
	  int _year;
	  std::string _make;
	  std::string _model;
	  Body_style _body_style;
};

#endif

