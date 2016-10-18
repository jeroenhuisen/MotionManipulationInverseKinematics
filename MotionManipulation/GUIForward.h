#pragma once

#include <gtkmm.h>
#include <exprtk.hpp>
#include <iostream>

#include "MiddleFingerRotation.h"

class GUIForward : public Gtk::Window {
public:
	GUIForward();
	//virtual ~GUIForward();

protected:
	//Signal handlers:
	void on_button_clicked();

	Gtk::Box box;

	Gtk::Entry entryThetaM;
	Gtk::Entry entryThetaP;
	Gtk::Entry entryThetaD;

	Gtk::Button calculateButton;

	Gtk::TextView returnText;
	Glib::RefPtr<Gtk::TextBuffer> textBuffer;

	
	MiddleFingerRotation mfr;

	float parseAngle(std::string angleString);
};