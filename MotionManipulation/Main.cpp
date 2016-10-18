#include <iostream>
#include <armadillo>
#include <gtkmm.h>

#include "GUIForward.h"
#include "MiddleFingerRotation.h"


using namespace std;
using namespace arma;

void roundMat(mat& a) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a.at(i, j) = round(a.at(i, j) * 100) / 100;
		}
	}
}


int on_cmd(const Glib::RefPtr<Gio::ApplicationCommandLine> &, Glib::RefPtr<Gtk::Application> &app)
{
	app->activate(); // <----
	return 0;
}

int main(int argc, char** argv){
	float pi = 3.14159265358979323846264338327950;
	std::cout << "welcome noob" << std::endl;
	mat a(4, 4);

	MiddleFingerRotation mfr;

	a = mfr.rotate(pi / 3, (-1 * pi) / 2, (-1 * pi)/3);
	roundMat(a);
	cout << a << endl;
	a = mfr.rotate(pi / 3, (-1 * pi) / 3);
	roundMat(a);
	mfr.rotateCoordinatesAndAngle(pi / 3, (-1 * pi) / 3);
	cout << a;

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.kinematics.ForwardGUI", Gio::APPLICATION_HANDLES_COMMAND_LINE);
	app->signal_command_line().connect(sigc::bind(sigc::ptr_fun(on_cmd), app), false);

	GUIForward window;
	//window.showMatrix(a);

	return app->run(window);
}

 