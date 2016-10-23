#pragma once
#pragma once

#include <gtkmm.h>
#include <exprtk.hpp>
#include <iostream>

#include "MiddleFinger.h"

class GUIInverse : public Gtk::Window {
public:
	GUIInverse();
	//virtual ~GUIInverse();

protected:
	//Signal handlers:
	void on_button_clicked();


	// normal input
	Gtk::Box inputBox;

	Gtk::Label labelCoordinateX;
	Gtk::Label labelCoordinateY;

	Gtk::Entry entryCoordinateX;
	Gtk::Entry entryCoordinateY;

	Gtk::Button calculateButton;

	Gtk::Label labelThetaM;
	Gtk::TextView thetaMOutput;
	Glib::RefPtr<Gtk::TextBuffer> thetaMOutputBuffer;

	Gtk::Label labelThetaP;
	Gtk::TextView thetaPOutput;
	Glib::RefPtr<Gtk::TextBuffer> thetaPOutputBuffer;

	Gtk::Label labelThetaD;
	Gtk::TextView thetaDOutput;
	Glib::RefPtr<Gtk::TextBuffer> thetaDOutputBuffer;

	// extra input
	Gtk::Box box;
	Gtk::Box extraInputBox;

	Gtk::Label labelEndCoordinateX;
	Gtk::Label labelEndCoordinateY;

	Gtk::Entry entryEndCoordinateX;
	Gtk::Entry entryEndCoordinateY;

	Gtk::Label labelInterval;
	Gtk::Entry entryInterval;


	MiddleFinger mF;

	float parseCoordinate(std::string coordinateString);
	bool isReachable(float coordinateX, float coordinateY);
};