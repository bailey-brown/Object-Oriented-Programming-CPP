#include "controller.h"
#include "main_window.h"
#include "dialogs.h"
#include <gtkmm.h>

int main(int argc, char *argv[]) {

   auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.mavmart.v1_0");
   
   Controller controller;
   Main_window win{controller};
   Dialogs::set_window(&win);
   
   return app->run(win);

}

