#include "GUIForward.h"

GUIForward::GUIForward() :
	box(Gtk::ORIENTATION_VERTICAL),
	calculateButton("Calculate"),
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

	entryThetaM.set_max_length(128);
	entryThetaP.set_max_length(128);
	entryThetaD.set_max_length(128);
	box.add(entryThetaM);
	box.add(entryThetaP);
	box.add(entryThetaD);
	box.add(calculateButton);

	textBuffer = Gtk::TextBuffer::create();
	textBuffer->set_text("textBuffer text");

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
	
	mat result;
	std::pair<float, float> coordinates;
	
	if (thetaDEntered){
		float thetaD = parseAngle(textThetaD);
		std::cout << "input: " << textThetaD << ", parsed: " << thetaD << std::endl;
		result = mfr.rotate(thetaM, thetaP, thetaD);
		
	}
	else {
		std::cout << "input: No input for thetaD using the restriction" << std::endl;
		//result = mfr.rotate(thetaM, thetaP);
		coordinates = mfr.rotateCoordinates(thetaM, thetaP);
	}
	float angle = mfr.rotateCoordinatesAndAngle(thetaM, thetaP);
	std::string coordinatesText = std::to_string(coordinates.first) + ", " + std::to_string(coordinates.second);
	textBuffer->set_text(coordinatesText);
	returnText.set_buffer(textBuffer);
}


float GUIForward::parseAngle(std::string input) {
	exprtk::expression<float> expression;
	exprtk::parser<float> parser;
	exprtk::symbol_table<float> symbol_table;
	
	symbol_table.add_constants();
	expression.register_symbol_table(symbol_table);

	parser.compile(input, expression);

	return expression.value();
	return 1.0f;
}