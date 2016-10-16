#include "GUIForward.h"

GUIForward::GUIForward() :
	box(Gtk::ORIENTATION_VERTICAL),
	sendButton("Send"),
	entry(),
	returnText()
{
	// Sets titel of the window
	set_title("GUI Forward kinematics");
	// Sets the border width of the window.
	set_border_width(0);

	//add(sendButton);
	sendButton.signal_clicked().connect(sigc::mem_fun(*this, &GUIForward::on_button_clicked));
	add(box);

	entry.set_max_length(128);
	box.add(entry);
	box.add(sendButton);

	textBuffer = Gtk::TextBuffer::create();
	textBuffer->set_text("textBuffer text");

	returnText.set_buffer(textBuffer);
	box.add(returnText);



	// The final step is to display this newly created widget...
	show_all_children();
}