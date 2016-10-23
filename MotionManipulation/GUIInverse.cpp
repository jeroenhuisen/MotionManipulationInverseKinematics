#include "GUIInverse.h"

GUIInverse::GUIInverse() :
	box(Gtk::ORIENTATION_HORIZONTAL),

	inputBox(Gtk::ORIENTATION_VERTICAL),
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
	thetaDOutput(),

	extraInputBox(Gtk::ORIENTATION_VERTICAL),
	labelEndCoordinateX("End x-coordinate"),
	labelEndCoordinateY("End y-coordinate"),
	entryEndCoordinateX(),
	entryEndCoordinateY(),
	labelInterval("Interval"),
	entryInterval()
{
	// Sets titel of the window
	set_title("GUI Inverse kinematics");
	// Sets the border width of the window.
	set_border_width(0);

	//add(sendButton);
	calculateButton.signal_clicked().connect(sigc::mem_fun(*this, &GUIInverse::on_button_clicked));
	add(box);

	box.add(inputBox);
	box.add(extraInputBox);

	//put it to 128 for no real reason just to limit it without being annoying
	entryCoordinateX.set_max_length(128);
	entryCoordinateY.set_max_length(128);

	inputBox.add(labelCoordinateX);
	inputBox.add(entryCoordinateX);

	inputBox.add(labelCoordinateY);
	inputBox.add(entryCoordinateY);

	inputBox.add(calculateButton);



	thetaMOutputBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	thetaMOutputBuffer->set_text("ThetaM result");

	thetaMOutput.set_buffer(thetaMOutputBuffer);
	inputBox.add(labelThetaM);
	inputBox.add(thetaMOutput);

	thetaPOutputBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	thetaPOutputBuffer->set_text("ThetaP result");

	thetaPOutput.set_buffer(thetaPOutputBuffer);
	inputBox.add(labelThetaP);
	inputBox.add(thetaPOutput);

	thetaDOutputBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	thetaDOutputBuffer->set_text("ThetaD result");

	thetaDOutput.set_buffer(thetaDOutputBuffer);
	inputBox.add(labelThetaD);
	inputBox.add(thetaDOutput);


	// Extra end coordinate
	extraInputBox.add(labelEndCoordinateX);
	extraInputBox.add(entryEndCoordinateX);

	extraInputBox.add(labelEndCoordinateY);
	extraInputBox.add(entryEndCoordinateY);

	extraInputBox.add(labelInterval);
	extraInputBox.add(entryInterval);


	// The final step is to display this newly created widget...
	show_all_children();
}


float linear(float startX, float endX, float startY, float endY, float interval, float currentX) {
	float amount = (currentX - startX) / interval;
	return (endY - startY) / interval * amount;
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

	// extra shit


	std::string textEndCoordinateX = entryEndCoordinateX.get_text();
	std::string textEndCoordinateY = entryEndCoordinateY.get_text();
	std::string textInterval = entryInterval.get_text();

	float endCoordinateX = parseCoordinate(textEndCoordinateX);
	float endCoordinateY = parseCoordinate(textEndCoordinateY);
	float interval = parseCoordinate(textInterval); //change parse name

	if (isnan(endCoordinateX)) {
		std::cerr << "Invalid input for end X-coordinate" << std::endl;
		//thetaMOutputBuffer->set_text("Invalid input for end X-coordinate");
		return;
	}
	if (isnan(endCoordinateY)) {
		std::cerr << "Invalid input for end Y-coordinate" << std::endl;
		//thetaPOutputBuffer->set_text("Invalid input for end Y-coordinate");
		return;
	}

	if (isnan(interval)) {
		std::cerr << "Invalid input for interval" << std::endl;
		//thetaPOutputBuffer->set_text("Invalid input for interval");
		return;
	}

	std::cout << "input: " << textEndCoordinateX << ", parsed: " << endCoordinateX << std::endl;
	std::cout << "input: " << textEndCoordinateY << ", parsed: " << endCoordinateY << std::endl;
	std::cout << "input: " << textInterval       << ", parsed: " << interval       << std::endl;

	for (float x = coordinateX; x <= endCoordinateX; x += interval) {
		float y = linear(coordinateX, endCoordinateX, coordinateY, endCoordinateY, interval, x);
		std::pair<float, float> result = mF.inverseRotate(x, y);
		std::cout << result.first << " and thetaP: " << result.second << std::endl;
	}
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