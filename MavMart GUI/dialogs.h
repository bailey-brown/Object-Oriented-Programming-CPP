#ifndef __DIALOGS_H
#define __DIALOGS_H

#include <iostream>
#include <gtkmm.h>

class Dialogs {
  public:
	static void message(std::string msg, std::string title = "info");
	static std::string input(std::string msg, std::string title, std::string default_text = "",
							 std::string cancel_text = "CANCEL");
	static int question(std::string msg, std::string title, 
						std::vector<std::string> buttons = {"Cancel", "OK"});
	static int multi_dialog(std::string title, std::string label1, std::string label2);
	static void set_window(Gtk::Window* win);
	

	static Gtk::Window* window;
};
#endif


	