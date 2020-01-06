#include "main_window.h"

Main_window::Main_window(Controller controller) : _controller{controller} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("MavMart");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_click));
    filemenu->append(*menuitem_save);

    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
    menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_load_click));
    filemenu->append(*menuitem_load);
	
    Gtk::MenuItem *menuitem_exit = Gtk::manage(new Gtk::MenuItem("_Exit", true));
    menuitem_exit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_exit_click));
    filemenu->append(*menuitem_exit);
	
	
	Gtk::MenuItem *menuitem_product = Gtk::manage(new Gtk::MenuItem("_Product", true));
    menubar->append(*menuitem_product);
    Gtk::Menu *productmenu = Gtk::manage(new Gtk::Menu());
    menuitem_product->set_submenu(*productmenu);
	
	Gtk::MenuItem *menuitem_add_product = Gtk::manage(new Gtk::MenuItem("_Add Product", true));
    menuitem_add_product->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_product_click));
    productmenu->append(*menuitem_add_product);

    Gtk::MenuItem *menuitem_list_products = Gtk::manage(new Gtk::MenuItem("_List All Products", true));
    menuitem_list_products->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_all_products_click));
    productmenu->append(*menuitem_list_products);
	
	
	Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menubar->append(*menuitem_order);
    Gtk::Menu *ordermenu = Gtk::manage(new Gtk::Menu());
    menuitem_order->set_submenu(*ordermenu);
	
	Gtk::MenuItem *menuitem_add_order = Gtk::manage(new Gtk::MenuItem("_Add order", true));
    menuitem_add_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_order_click));
    ordermenu->append(*menuitem_add_order);

    Gtk::MenuItem *menuitem_list_orders = Gtk::manage(new Gtk::MenuItem("_List All Orders", true));
    menuitem_list_orders->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_all_orders_click));
    ordermenu->append(*menuitem_list_orders);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_help_click));
    helpmenu->append(*menuitem_about);
	
	msg = Gtk::manage(new Gtk::Label{"C1325 MAVMART"});
    msg->set_hexpand(true);
    vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

}

Main_window::~Main_window() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Main_window::on_add_product_click() {
	_controller.execute_cmd(1);
}

void Main_window::on_list_all_products_click() {
	_controller.execute_cmd(2);
}

void Main_window::on_add_order_click() {
	_controller.execute_cmd(4);
}

void Main_window::on_list_all_orders_click() {
	_controller.execute_cmd(5);
}

void Main_window::on_save_click() {
	_controller.execute_cmd(6);

}

void Main_window::on_load_click() {
	_controller.execute_cmd(7);

}

void Main_window::on_exit_click() {
    close();
}

void Main_window::on_help_click() {
	_controller.execute_cmd(9);
}


