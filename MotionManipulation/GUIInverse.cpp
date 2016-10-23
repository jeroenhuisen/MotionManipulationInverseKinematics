#include "GUIInverse.h"

GUIInverse::GUIInverse() :
	box(Gtk::ORIENTATION_VERTICAL),
	calculateButton("Calculate"),
	labelCoordinateX("X-coordinate"),
	labelCoordinateY("Y-coordinate"),
	entryCoordinateX(),
	entryCoordinateY(),
	labelThetaM("Theta M"),
	labelThetaP("Theta P"),
	labelThetaD("Theta D"),
	thetaMOutput(),
	thetaPOutput(),
	thetaDOutput()
{
	// Sets titel of the window
	set_title("GUI Forward kinematics");
	// Sets the border width of the window.
	set_border_width(0);

	//add(sendButton);
	calculateButton.signal_clicked().connect(sigc::mem_fun(*this, &GUIInverse::on_button_clicked));
	add(box);

	//put it to 128 for no real reason just to limit it without being annoying
	entryCoordinateX.set_max_length(128);
	entryCoordinateY.set_max_length(128);

	box.add(labelCoordinateX);
	box.add(entryCoordinateX);

	box.add(labelCoordinateY);
	box.add(entryCoordinateY);

	box.add(calculateButton);



	thetaMOutputBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	thetaMOutputBuffer->set_text("ThetaM result");

	thetaMOutput.set_buffer(thetaMOutputBuffer);
	box.add(labelThetaM);
	box.add(thetaMOutput);

	thetaPOutputBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	thetaPOutputBuffer->set_text("ThetaP result");

	thetaPOutput.set_buffer(thetaPOutputBuffer);
	box.add(labelThetaP);
	box.add(thetaPOutput);

	thetaDOutputBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	thetaDOutputBuffer->set_text("ThetaD result");

	thetaDOutput.set_buffer(thetaDOutputBuffer);
	box.add(labelThetaD);
	box.add(thetaDOutput);


	// The final step is to display this newly created widget...
	show_all_children();
}

void GUIInverse::on_button_clicked() {
	std::cout << "button pressed" << std::endl;

	std::string textCoordinateX = entryCoordinateX.get_text();
	std::string textCoordinateY = entryCoordinateY.get_text();


	float coordinateX = parseCoordinate(textCoordinateX);
	float coordinateY = parseCoordinate(textCoordinateY);

	if (isnan(coordinateX)) {
		std::cerr << "Invalid input for X-coordinate" << std::endl;
		thetaMOutputBuffer->set_text("Invalid input for X-coordinate");
		return;
	}
	if (isnan(coordinateY)) {
		std::cerr << "Invalid input for Y-coordinate" << std::endl;
		thetaPOutputBuffer->set_text("Invalid input for Y-coordinate");
		return;
	}

	std::cout << "input: " << textCoordinateX << ", parsed: " << coordinateX << std::endl;
	std::cout << "input: " << textCoordinateY << ", parsed: " << coordinateY << std::endl;

	if (!isReachable(coordinateX, coordinateY)) {
		std::cerr << "Unreachable coordinates: " << coordinateX << ", " << coordinateY << std::endl;
		return;
	}

	std::pair<float, float> result = mF.inverseRotate(coordinateX, coordinateY);
	float thetaM = result.first;
	float thetaP = result.second;

	std::cout << "ThetaM: " << thetaM << std::endl;
	std::cout << "ThetaP: " << thetaP << std::endl;


	thetaMOutputBuffer->set_text(std::to_string(thetaM));
	thetaPOutputBuffer->set_text(std::to_string(thetaP));
	thetaDOutputBuffer->set_text(std::to_string(2*thetaP/3));
}


float GUIInverse::parseCoordinate(std::string input) {
	exprtk::expression<float> expression;
	exprtk::parser<float> parser;
	exprtk::symbol_table<float> symbol_table;

	symbol_table.add_constants();
	expression.register_symbol_table(symbol_table);

	parser.compile(input, expression);

	return expression.value();
}

bool GUIInverse::isReachable(float coordinateX, float coordinateY) {
	// should be improved
	return true;
}