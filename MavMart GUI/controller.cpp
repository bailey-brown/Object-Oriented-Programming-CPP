#include "controller.h"
#include <dirent.h>
#include <fstream>
#include <experimental/filesystem>

Controller::Controller() { }
Controller::Controller(Store store) : _store{store} { }


void Controller::gui() {
	
	int input = 1;
	std::string text;
	
	while(input) {
		
		text = Dialogs::input(_view.main_menu(), "Main Menu");
		std::istringstream ist{text};
		ist >> input;
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
		case 6 : save(); break;
		case 7 : load(); break;
		case 9 : help(); break;
		case 0 : break;
		default : std::cout << "Invalid input" << std::endl; cmd = 0; break;
	}
}
	
void Controller::add_product() {
	
	std::string name;
	double price;
	
	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_transient_for(*(Dialogs::window));
    dialog->set_title("Add Product");

    // Name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name: "};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

   // num
    Gtk::HBox b_num;

    Gtk::Label l_num{"Price: "};
    l_num.set_width_chars(15);
    b_num.pack_start(l_num, Gtk::PACK_SHRINK);

    Gtk::Entry e_num;
    e_num.set_max_length(50);
    b_num.pack_start(e_num, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_num, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
 

    if (result == 1) {
        name = e_name.get_text();
        price = std::stod(e_num.get_text());
        _store.add_product(Product{name, price});
    }
	
	delete dialog;

}

void Controller::list_all_products() {
	std::string store = get_string(_store);
	Dialogs::message(store, "Available Products");      
}
	
void Controller::add_order() {
	
	std::string email;
	std::string product;
	std::string text;
	int OrderNum;
	int quantity;
	int index;
	int run = 1;
	
	email = Dialogs::input("Enter email address: ", "Add Order");
	
	if(email == "CANCEL") { run = 0; }
	else { OrderNum = _store.create_order(email); }
	
	
	while(run)
	{
		
		Gtk::Dialog *dialog = new Gtk::Dialog();
		dialog->set_transient_for((*Dialogs::window));
		dialog->set_title("Add Order");
		
		std::string p = get_string(_store);
		Gtk::Label *label = new Gtk::Label(p);
		label->set_use_markup(true);
		dialog->get_content_area()->pack_start(*label);
		label->show();

    // Name
		Gtk::HBox b_name;

		Gtk::Label l_name{"Product Index: "};
		l_name.set_width_chars(15);
		b_name.pack_start(l_name, Gtk::PACK_SHRINK);

		Gtk::Entry e_name;
		e_name.set_max_length(50);
		b_name.pack_start(e_name, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

   // num
		Gtk::HBox b_num;

		Gtk::Label l_num{"Quantity: "};
		l_num.set_width_chars(15);
		b_num.pack_start(l_num, Gtk::PACK_SHRINK);

		Gtk::Entry e_num;
		e_num.set_max_length(50);
		b_num.pack_start(e_num, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_num, Gtk::PACK_SHRINK);

    // Show dialog
		dialog->add_button("Cancel", 0);
		dialog->add_button("OK", 1);
		dialog->show_all();
		int result = dialog->run();

		dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();
 

		if (result == 1) {
			index = std::stod(e_name.get_text());
			quantity = std::stod(e_num.get_text());
			try {
				_store.add_to_order(OrderNum, Product_order{_store.product(index), quantity});
			}
			catch(std::out_of_range& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else { run = 0; }
		
		delete dialog;
		delete label;
	}
	
	
	
	

}	
	
void Controller::list_all_orders() {
	
	std::ostringstream ost;
	int i;
	for (i=0; i<_store.num_orders(); i++) {
		ost <<"Order " << i+1 << ")\n" << _store.order(i) << "\n";
	}
	
	Dialogs::message(ost.str(), "Current Orders");
}

void Controller::help() {
	Dialogs::message(_view.help(), "Help Menu");
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

void Controller::load() {
    for(auto& p: std::experimental::filesystem::directory_iterator(".")) {
        if(p.path().extension() == ".dat") std::cout << p << '\n';
    }
	
    std::string ifile;
	ifile = Dialogs::input("Filename to load? ", "Load File");
	if(ifile == "CANCEL") { return; }
    std::ifstream ifs{ifile};
    if (ifs) _store = Store{ifs};
    else std::cerr << "Unable to open for load: " << ifile << std::endl;
}

void Controller::save() {
    std::string ofile;
    ofile = Dialogs::input("Filename to save? ", "Save File");
    if(ofile == "CANCEL") { return; };
    std::ofstream ofs{ofile};
    if (ofs) _store.save(ofs);
    else std::cerr << "Unable to open for save: " << ofile << std::endl;
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

std::string Controller::get_string(auto a) {
	
	std::ostringstream ost;
	ost	<< a;
	return ost.str();
}
	






