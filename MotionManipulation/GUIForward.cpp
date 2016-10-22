#include "GUIForward.h"

GUIForward::GUIForward() :
	box(Gtk::ORIENTATION_VERTICAL),
	calculateButton("Calculate"),
	labelThetaM(),
	labelThetaP(),
	labelThetaD(),
	entryThetaM(),
	entryThetaP(),
	entryThetaD(),
	returnText()
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

	labelThetaM.set_text("Theta M");
	labelThetaP.set_text("Theta P");
	labelThetaD.set_text("Theta D");

	box.add(labelThetaM);
	box.add(entryThetaM);

	box.add(labelThetaP);
	box.add(entryThetaP);

	box.add(labelThetaD);
	box.add(entryThetaD);

	box.add(calculateButton);

	textBuffer = Gtk::TextBuffer::create();
	// Only the first two angles are required
	textBuffer->set_text("Please enter the angles");

	returnText.set_buffer(textBuffer);
	box.add(returnText);



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
	
	std::cout << "input: " << textThetaM << ", parsed: " << thetaM << std::endl;
	std::cout << "input: " << textThetaP << ", parsed: " << thetaP << std::endl;

	if (thetaM > PI / 2 || thetaM < -PI / 2) {
		std::cerr << "thetaM is not in the domain [-pi/2, pi/2] but has value: " << thetaM << std::endl;
		textBuffer->set_text("thetaM is not in the domain [-pi/2, pi/2]");
		return;
	}

	if (thetaP > 0|| thetaP < -PI / 2) {
		std::cerr << "thetaP is not in the domain [-pi/2, 0] but has value: " << thetaP << std::endl;
		textBuffer->set_text("thetaP is not in the domain [-pi/2, 0]");
		return;
	}
	
	//mat result;
	std::pair<float, float> coordinates;
	
	if (thetaDEntered){
		float thetaD = parseAngle(textThetaD);
		std::cout << "input: " << textThetaD << ", parsed: " << thetaD << std::endl;
		coordinates = mF.rotateCoordinates(thetaM, thetaP, thetaD);
		
	}
	else {
		std::cout << "input: No input for thetaD using the restriction" << std::endl;
		//result = mfr.rotate(thetaM, thetaP);
		coordinates = mF.rotateCoordinates(thetaM, thetaP);
	}
	std::string coordinatesText = std::to_string(coordinates.first) + ", " + std::to_string(coordinates.second);
	textBuffer->set_text(coordinatesText);
	returnText.set_buffer(textBuffer);


	// test remove this
	std::pair<float, float> result = mF.inverseRotate(coordinates.first, coordinates.second);
	std::cout << result.first << std::endl;
	std::cout << result.second << std::endl;
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