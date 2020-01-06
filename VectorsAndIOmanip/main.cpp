

#include "gas_vehicle.h"
#include "electric_vehicle.h"
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::vector<double> cost_per_gallon = {2.00, 2.25, 2.50, 3.00, 4.00};
    std::vector<double> cost_per_kwh = {0.05, 0.08, 0.11, 0.13, 0.15};
 
    std::vector<Electric_vehicle> evs = {
        Electric_vehicle{2014, "Telsa", "Model S 85", Body_style::SEDAN, 3.12, 85},
        Electric_vehicle{2014, "Telsa", "Model 3 LR", Body_style::SEDAN, 4.13, 75},
        Electric_vehicle{2018, "GM", "Bolt", Body_style::HATCHBACK, 3.58, 60},
        Electric_vehicle{2018, "Nissan", "LEAF SL", Body_style::HATCHBACK, 3.88, 40},
    };
    std::vector<Gas_vehicle> ice = {
        Gas_vehicle{2017, "Toyota", "RAV4", Body_style::SUV, 26, 15.9},
        Gas_vehicle{2018, "Ford", "F-150", Body_style::SUV, 21, 36},
        Gas_vehicle{2018, "Nissan", "Rogue", Body_style::HATCHBACK, 29, 14.5},
        Gas_vehicle{2018, "Chrysler", "Pacifica", Body_style::SUV, 22, 19},
    };
	
	for (auto pkwh : cost_per_kwh) {
        std::cout << std::setw(9) << pkwh;
	}

	std::cout << "   Cost per kWh" << std::endl;

	for (auto pgal : cost_per_gallon) {
        std::cout << std::setw(9) << std::setprecision(2) << std::fixed << pgal;
	}
	std::cout << "   Cost per gallon"  << std::endl;
	
	std::string l; l.resize(8, '=');
	std::string m; m.resize(30, '=');
	
	for (auto pgal : cost_per_gallon) {
        std::cout << std::setw(9) << l;
	}
	std::cout << "   " << m << std::endl;
	
	for (auto ev : evs) {
        for (auto pkwh : cost_per_kwh) {
            std::cout << std::setw(9) << std::setprecision(2) << std::fixed << pkwh * ev.kwh_consumed(100);
		}
		std::cout << "   " << ev << std::endl;
	}
	
		for (auto pgal : cost_per_gallon) {
        std::cout << " " << l;
	}
	std::cout << "   " << m << std::endl;
	
	for (auto ev : evs) {
        for (auto pkwh : cost_per_kwh) {
            std::cout << std::setw(9) << std::setprecision(2) << std::fixed << pkwh * ev.kwh_consumed(100);
		}
		std::cout << "   " << ev << std::endl;
	}

	

}
