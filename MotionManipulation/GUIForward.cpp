#include "GUIForward.h"

GUIForward::GUIForward() :
	box(Gtk::ORIENTATION_VERTICAL),
	calculateButton("Calculate"),
	labelThetaM("Theta M"),
	labelThetaP("Theta P"),
	labelThetaD("Theta D"),
	entryThetaM(),
	entryThetaP(),
	entryThetaD(),
	labelCoordinates("Coordinates of the tip"),
	coordinatesOutput(),
	labelAngle("Angle of the tip"),
	angleOutput()
{
	// Sets titel of the window
	set_title("GUI Forward kinematics");
	// Sets the border width of the window.
	set_border_width(0);

	//add(sendButton);
	calculateButton.signal_clicked().connect(sigc::mem_fun(*this, &GUIForward::on_button_clicked));
	add(box);

	//put it to 128 for no real reason just to limit it without being annoying
	entryThetaM.set_max_length(128);
	entryThetaP.set_max_length(128);
	entryThetaD.set_max_length(128);

	box.add(labelThetaM);
	box.add(entryThetaM);

	box.add(labelThetaP);
	box.add(entryThetaP);

	box.add(labelThetaD);
	box.add(entryThetaD);

	box.add(calculateButton);

	coordinatesOutputBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	coordinatesOutputBuffer->set_text("Please enter the angles");

	coordinatesOutput.set_buffer(coordinatesOutputBuffer);
	box.add(labelCoordinates);
	box.add(coordinatesOutput);


	angleOutputBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	angleOutputBuffer->set_text("Press calculate");

	angleOutput.set_buffer(angleOutputBuffer);
	box.add(labelAngle);
	box.add(angleOutput);


	// The final step is to display this newly created widget...
	show_all_children();
}

void GUIForward::on_button_clicked() {
	std::cout << "button pressed" << std::endl;
	bool thetaDEntered = false;

	std::string textThetaM = entryThetaM.get_text();
	std::string textThetaP = entryThetaP.get_text();
	std::string textThetaD = entryThetaD.get_text();

	if (textThetaD != "") {
		thetaDEntered = true;
	}

	float thetaM = parseAngle(textThetaM);
	float thetaP = parseAngle(textThetaP);

	if (isnan(thetaM)) {
		std::cerr << "Invalid input for thetaM" << std::endl;
		coordinatesOutputBuffer->set_text("Invalid input for thetaM");
		return;
	}
	if (isnan(thetaP)) {
		std::cerr << "Invalid input for thetaP" << std::endl;
		coordinatesOutputBuffer->set_text("Invalid input for thetaP");
	}
	
	std::cout << "input: " << textThetaM << ", parsed: " << thetaM << std::endl;
	std::cout << "input: " << textThetaP << ", parsed: " << thetaP << std::endl;

	if (thetaM > PI / 3 || thetaM < -PI / 3) {
		std::cerr << "ThetaM is not in the domain [-pi/3, pi/3] but has value: " << thetaM << std::endl;
		coordinatesOutputBuffer->set_text("ThetaM is not in the domain [-pi/3, pi/3]");
		return;
	}

	if (thetaP > 0|| thetaP < -2*PI / 3) {
		std::cerr << "ThetaP is not in the domain [-2pi/3, 0] but has value: " << thetaP << std::endl;
		coordinatesOutputBuffer->set_text("ThetaP is not in the domain [-2pi/3, 0]");
		return;
	}

	std::pair<float, float> coordinates;
	float angle;
	
	if (thetaDEntered){
		float thetaD = parseAngle(textThetaD);
		std::cout << "input: " << textThetaD << ", parsed: " << thetaD << std::endl;

		if (thetaD > 0 || thetaD < -2 * PI / 3) {
			std::cerr << "ThetaD is not in the domain [-2pi/3, 0] but has value: " << thetaD << std::endl;
			coordinatesOutputBuffer->set_text("ThetaD is not in the domain [-2pi/3, 0]");
			return;
		}

		coordinates = mF.rotateCoordinates(thetaM, thetaP, thetaD);	
		angle = mF.tipAngle(thetaM, thetaP, thetaD);
	}

	else {
		std::cout << "input: No input for thetaD using the restriction" << std::endl;
		coordinates = mF.rotateCoordinates(thetaM, thetaP);
		angle = mF.tipAngle(thetaM, thetaP);
	}
	std::string coordinatesText = std::to_string(coordinates.first) + ", " + std::to_string(coordinates.second);
	coordinatesOutputBuffer->set_text(coordinatesText);
	angleOutputBuffer->set_text(std::to_string(angle));


	// test remove this
	std::pair<float, float> result = mF.inverseRotate(coordinates.first, coordinates.second);
	std::cout << "ThetaM: " << result.first << std::endl;
	std::cout << "ThetaP: " << result.second << std::endl;
}


float GUIForward::parseAngle(std::string input) {
	exprtk::expression<float> expression;
	exprtk::parser<float> parser;
	exprtk::symbol_table<float> symbol_table;
	
	symbol_table.add_constants();
	expression.register_symbol_table(symbol_table);

	parser.compile(input, expression);

	return expression.value();
}