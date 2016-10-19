#pragma once

#include <gtkmm.h>
#include <exprtk.hpp>
#include <iostream>

#include "MiddleFinger.h"

class GUIForward : public Gtk::Window {
public:
	GUIForward();
	//virtual ~GUIForward();

protected:
	//Signal handlers:
	void on_button_clicked();

	Gtk::Box box;

	Gtk::Label labelThetaM;
	Gtk::Label labelThetaP;
	Gtk::Label labelThetaD;

	Gtk::Entry entryThetaM;
	Gtk::Entry entryThetaP;
	Gtk::Entry entryThetaD;

	Gtk::Button calculateButton;

	Gtk::TextView returnText;
	Glib::RefPtr<Gtk::TextBuffer> textBuffer;

	
	MiddleFinger mF;

	float parseAngle(std::string angleString);
};