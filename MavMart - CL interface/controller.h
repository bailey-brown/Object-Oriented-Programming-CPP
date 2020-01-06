#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include "store.h"
#include "view.h"
#include <iostream>
#include <sstream>
#include <string>

class Controller {

  public:
	Controller();
	Controller(Store store);
	
	void cli();
	void execute_cmd(int cmd);
	void add_product();
	void list_all_products();
	void add_order();
	void list_all_orders();
	void easter_egg();
	void help();
	
	
  private:
	Store _store{"MavMart"};
	View _view{_store};
	
	double get_double(std::string prompt);
	int get_int(std::string prompt);
};

#endif
	