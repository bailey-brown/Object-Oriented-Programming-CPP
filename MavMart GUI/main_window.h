#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "controller.h"

class Main_window : public Gtk::Window
{
    public:
        Main_window(Controller controller);
        virtual ~Main_window();
    protected:
        void on_add_product_click();  
        void on_list_all_products_click();         
        void on_add_order_click();        
        void on_list_all_orders_click();         
        void on_save_click(); 
        void on_load_click(); 
		void on_help_click();        
        void on_exit_click();            
    private:                   
        Controller _controller;                             
        Gtk::Label *msg;                      	

};
#endif 

