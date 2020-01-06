#include "controller.h"

Controller::Controller() { }
Controller::Controller(Store store) : _store{store} { }


void Controller::cli() {
	
	int input = 1;
	while(input) {
		
		std::cout << _view.main_menu();
		
		input = get_int("Command? ");
		execute_cmd(input);
	}
}
	
void Controller::execute_cmd(int cmd) {
	
	switch(cmd) {
		case 1 : add_product(); break;
		case 2 : list_all_products(); break;
		case 3 : easter_egg(); break;
		case 4 : add_order(); break;
		case 5 : list_all_orders (); break;
		case 9 : help(); break;
		case 0 : break;
		default : std::cout << "Invalid input" << std::endl; cmd = 0; break;
	}
}
	
void Controller::add_product() {
	
	std::string name;
	double price;
	
	std::cout << "\nEnter product name: ";
	std::cin >> name;
	price = get_double("Enter product price (real numbers only): ");
	
	Product product{name, price};
	_store.add_product(product);
}

void Controller::list_all_products() {
	std::cout << "\nCurrent Products:\n";
	std::cout << _store;
        
}
	
void Controller::add_order() {
	
	std::string email;
	std::string product;
	int quantity;
	int index;
	int run = 1;
	
	std::cout << "\nEnter email address: ";
	std::cin >> email;
	
	int OrderNum = _store.create_order(email);
	
	while(run)
	{
		Controller::list_all_products();
		std::cout << "\nEnter the product index followed by a space and the quantity or 'done' to complete order: ";
		std::cin >> product;
		if(product == "done") {run = 0; continue;}
		std::cin >> quantity;
		
		index = std::stoi(product);
		
		try {
		_store.add_to_order(OrderNum, Product_order{_store.product(index), quantity});
		}
		catch(std::out_of_range& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}	
	
void Controller::list_all_orders() {
	
	int i;
	for (i=0; i<_store.num_orders(); i++) {
		std::cout <<"\nOrder for " << _store.order(i).email() << "\n" << _store.order(i) << std::endl;
	}
}

void Controller::help() {
	std::cout << _view.help();
}

void Controller::easter_egg() {
	
	_store.add_product(Product{"Candy", 2.99});
	_store.add_product(Product{"Popcorn", 3.99});
	_store.add_product(Product{"Peanut Butter", 4.00});
	_store.add_product(Product{"Chips", 3.99});
	_store.add_product(Product{"Cereal", 5.99});
	_store.add_product(Product{"Apples", 4.00});
	_store.add_product(Product{"Milk", 4.99});
	_store.add_product(Product{"Umbrellas", 15.00});
}







double Controller::get_double(std::string prompt) {

	double RetDouble;
	std::string StrNum;

	while(true) {

		std::cout << prompt;
		std::cin >> StrNum; 
		std::stringstream convert(StrNum);

		if(convert >> RetDouble && !(convert >> StrNum)) return RetDouble;

		std::cin.clear();
		std::cerr << "Input Invalid. Please try again.\n";
	}
}

int Controller::get_int(std::string prompt) {
	
	int RetInt;
	std::string StrNum;

	while(true) {

		std::cout << prompt;
		std::cin >> StrNum; 
		std::stringstream convert(StrNum); 

		if(convert >> RetInt && !(convert >> StrNum)) return RetInt;

		std::cin.clear(); 
		std::cerr << "Input Invalid. Please try again.\n";
	}
}






