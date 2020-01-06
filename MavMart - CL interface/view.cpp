#include "view.h"

View::View(Store& store) : _store{store} { }

std::string View::main_menu() 
{

	return R"(

	         ========================
	         Welcome to C1325 MavMart
	         ========================
	
Products                 Orders                Utility
--------                 ------                -------
(1) Add Product          (4) Place Order       (9) Help
(2) List all products    (5) List all orders   (0) Exit

)";	

}

std::string View::help() 
{
	return R"(
	
Welcome to the C1325 MavMart help menu!
	
Enter 1 to add a product to the store. You'll be asked to enter a product name 
        and price.
Enter 2 to see all the products sold by the store.
Enter 3 to load a predefined selection of products to the store. 
Enter 4 if you'd like to place an order. You will be asked to enter an email 
        address and then the index of the product you would like to order, 
        followed by a space, and the quantity of that product you would like. 
Enter 5 to see a list of the current orders that have been placed.
Enter 0 if you are done and would like to exit the program.
		
	)";
}
	