#pragma once

#include <gtkmm.h>
#include <iostream>

class GUIForward : public Gtk::Window {
public:
	GUIForward();
	virtual ~GUIForward();

protected:
	//Signal handlers:
	void on_button_clicked();

	Gtk::Box box;

	Gtk::Entry entry;
	Gtk::Button sendButton;

	Gtk::TextView returnText;
	Glib::RefPtr<Gtk::TextBuffer> textBuffer;
};