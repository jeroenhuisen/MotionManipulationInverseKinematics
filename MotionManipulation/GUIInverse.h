#pragma once
#pragma once

#include <gtkmm.h>
#include <exprtk.hpp>
#include <iostream>

#include "MiddleFinger.h"

#include "TestGraph.h"
#include "GraphArea.h"

class GUIInverse : public Gtk::Window {
private:
	float startCoordinateX, startCoordinateY;
	float endCoordinateX, endCoordinateY;

	std::vector<std::pair<float, float>> anglesArray;
	int anglesArrayLength;
	int currentPositionAnglesArray;

	float interval;


	bool getInputValueStartCoordinates();
	bool getInputValueEndCoordinates();
	bool getInputValueInterval();

	void calculateAngles(float coordinateX, float coordinateY);
	void calculateAllAngles();

	

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

	Gtk::Label labelError;
	Gtk::TextView errorOutput;
	Glib::RefPtr<Gtk::TextBuffer> errorOutputBuffer;

	// extra input
	Gtk::Box box;
	Gtk::Box extraInputBox;

	Gtk::Label labelEndCoordinateX;
	Gtk::Label labelEndCoordinateY;

	Gtk::Entry entryEndCoordinateX;
	Gtk::Entry entryEndCoordinateY;

	Gtk::Label labelInterval;
	Gtk::Entry entryInterval;

	//TestGraph graph;
	//SFMLWidget sfmlWidget;

	Gtk::Box drawBox;
	GraphArea graphArea;

	Gtk::Button previousIntervalButton;
	Gtk::Button nextIntervalButton;

	MiddleFinger mF;

	float parseCoordinate(std::string coordinateString);
	bool isReachable(float coordinateX, float coordinateY);

	bool updateDrawing(Gtk::ScrollType st, double value);
	void updateValues(std::pair<float, float> result);

	void previousInterval();
	void nextInterval();
};