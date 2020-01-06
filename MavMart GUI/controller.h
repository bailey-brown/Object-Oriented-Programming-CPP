#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include "store.h"
#include "view.h"
#include "dialogs.h"
#include <iostream>
#include <sstream>
#include <string>

class Controller {

  public:
	Controller();
	Controller(Store store);
	
	void gui();
	void execute_cmd(int cmd);
	void add_product();
	void list_all_products();
	void add_order();
	void list_all_orders();
	void easter_egg();
	void help();
	void load();
	void save();
	
	
  private:
	Store _store{"MavMart"};
	View _view{_store};
	
	double get_double(std::string prompt);
	int get_int(std::string prompt);
	std::string get_string(auto a);
};

#endif
	