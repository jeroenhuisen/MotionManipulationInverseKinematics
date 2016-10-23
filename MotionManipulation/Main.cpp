#include <iostream>
#include <armadillo>
#include <gtkmm.h>

#include "GUIForward.h"
#include "GUIInverse.h"

#include <SFML/Graphics.hpp>



using namespace std;
using namespace arma;

int on_cmd(const Glib::RefPtr<Gio::ApplicationCommandLine> &, Glib::RefPtr<Gtk::Application> &app)
{
	app->activate(); // <----
	return 0;
}

int main(int argc, char** argv){
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.kinematics.ForwardGUI", Gio::APPLICATION_HANDLES_COMMAND_LINE);
	app->signal_command_line().connect(sigc::bind(sigc::ptr_fun(on_cmd), app), false);

	GUIForward forwardWindow;
	GUIInverse inverseWindow;


	return app->run(inverseWindow);
}

 