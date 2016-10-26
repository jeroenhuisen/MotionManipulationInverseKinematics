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
	labelError("Error"),
	errorOutput(),

	extraInputBox(Gtk::ORIENTATION_VERTICAL),
	labelEndCoordinateX("End x-coordinate"),
	labelEndCoordinateY("End y-coordinate"),
	entryEndCoordinateX(),
	entryEndCoordinateY(),
	labelInterval("Interval"),
	entryInterval(),
	drawBox(Gtk::ORIENTATION_VERTICAL),
	previousIntervalButton("<"),
	nextIntervalButton(">"),
	adjustment(Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0)),
	scale(adjustment, Gtk::ORIENTATION_HORIZONTAL)/*,
	sfmlWidget(sf::VideoMode(640, 480)),
	graph(sfmlWidget)*/
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
	box.add(drawBox);

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

	errorOutputBuffer = Gtk::TextBuffer::create();
	errorOutputBuffer->set_text("");
	errorOutput.set_buffer(errorOutputBuffer);
	inputBox.add(labelError);
	inputBox.add(errorOutput);


	// Extra end coordinate
	extraInputBox.add(labelEndCoordinateX);
	extraInputBox.add(entryEndCoordinateX);

	extraInputBox.add(labelEndCoordinateY);
	extraInputBox.add(entryEndCoordinateY);

	extraInputBox.add(labelInterval);
	extraInputBox.add(entryInterval);

	//sfmlWidget.display();
	//extraInputBox.add(sfmlWidget);
	graphArea.set_size_request(600, 600);
	drawBox.add(graphArea);

	nextIntervalButton.signal_clicked().connect(sigc::mem_fun(*this, &GUIInverse::nextInterval));
	drawBox.add(nextIntervalButton);
	previousIntervalButton.signal_clicked().connect(sigc::mem_fun(*this, &GUIInverse::previousInterval));
	drawBox.add(previousIntervalButton);

	scale.set_digits(2);
	scale.set_value_pos(Gtk::POS_BOTTOM);
	scale.set_draw_value();
	scale.signal_change_value().connect(sigc::mem_fun(*this, &GUIInverse::updateDrawing));
	drawBox.add(scale);
	
	// The final step is to display this newly created widget...
	show_all_children();
}


float linear(float startX, float endX, float startY, float endY, float interval, float currentX) {
	/*float length = sqrt(pow((endX - startX), 2) + pow((endY - startY), 2));
	float amount =  length/ interval; //amount of steps
	float current = (currentX - startX) / interval; //the current step number

	return startY + (endY - startY) / amount * current;*/
	
	
	float slope = (endY - startY) / (endX - startX);
	/*if (endY < startY) {
		float temp = startY;
		startY = endY;
		endY = temp;
	}
	if (endX < startX) {
		float temp = startX;
		startX = endX;
		endX = temp;
	}*/

	return slope * (currentX - startX) + startY;
}


bool GUIInverse::getInputValueStartCoordinates() {
	std::string textCoordinateX = entryCoordinateX.get_text();
	std::string textCoordinateY = entryCoordinateY.get_text();

	startCoordinateX = parseCoordinate(textCoordinateX);
	startCoordinateY = parseCoordinate(textCoordinateY);

	if (isnan(startCoordinateX)) {
		std::cerr << "Invalid input for X-coordinate" << std::endl;
		thetaMOutputBuffer->set_text("Invalid input for X-coordinate");
		return false;
	}
	if (isnan(startCoordinateY)) {
		std::cerr << "Invalid input for Y-coordinate" << std::endl;
		thetaPOutputBuffer->set_text("Invalid input for Y-coordinate");
		return false;
	}

	std::cout << "input: " << textCoordinateX << ", parsed: " << startCoordinateX << std::endl;
	std::cout << "input: " << textCoordinateY << ", parsed: " << startCoordinateY << std::endl;

	if (!isReachable(startCoordinateX, startCoordinateY)) {
		std::cerr << "Unreachable coordinates: " << startCoordinateX << ", " << startCoordinateY << std::endl;
		return false;
	}
	return true;
}

bool GUIInverse::getInputValueEndCoordinates() {


	std::string textEndCoordinateX = entryEndCoordinateX.get_text();
	std::string textEndCoordinateY = entryEndCoordinateY.get_text();

	if (textEndCoordinateX == "" || textEndCoordinateY == "") {
		return false;
	}

	endCoordinateX = parseCoordinate(textEndCoordinateX);
	endCoordinateY = parseCoordinate(textEndCoordinateY);
	

	if (isnan(endCoordinateX)) {
		std::cerr << "Invalid input for end X-coordinate" << std::endl;
		//thetaMOutputBuffer->set_text("Invalid input for end X-coordinate");
		return false;
	}
	if (isnan(endCoordinateY)) {
		std::cerr << "Invalid input for end Y-coordinate" << std::endl;
		//thetaPOutputBuffer->set_text("Invalid input for end Y-coordinate");
		return false;
	}

	std::cout << "input: " << textEndCoordinateX << ", parsed: " << endCoordinateX << std::endl;
	std::cout << "input: " << textEndCoordinateY << ", parsed: " << endCoordinateY << std::endl;

	return true;
}

bool GUIInverse::getInputValueInterval() {
	std::string textInterval = entryInterval.get_text();

	if (textInterval == "") {
		return false;
	}

	interval = parseCoordinate(textInterval); //change parse name

	if (isnan(interval)) {
		std::cerr << "Invalid input for interval" << std::endl;
		//thetaPOutputBuffer->set_text("Invalid input for interval");
		return false;
	}
	std::cout << "input: " << textInterval << ", parsed: " << interval << std::endl;

	return true;
}

void GUIInverse::calculateAngles(float coordinateX, float coordinateY) {
	std::pair<float, float> result = mF.inverseRotate(coordinateX, coordinateY);
	float thetaM = result.first;
	float thetaP = result.second;

	if (isnan(result.first)) {
		std::cerr << "Unreachable coordinates: " << coordinateX << ", " << coordinateY << std::endl;
		errorOutputBuffer->set_text("Unreachable coordinates");
	}

	if (!(thetaM >= -PI / 3 - FLOAT_ERROR&& thetaM <= PI / 3 + FLOAT_ERROR)) {
		std::cerr << "ThetaM: " << thetaM << " is outside of the allowed domain" << std::endl;
		errorOutputBuffer->set_text("Unreachable coordinates");
	}
	if (!(thetaP >= -2 * PI / 3 - FLOAT_ERROR && thetaP <= 0 + FLOAT_ERROR)) {
		std::cerr << "ThetaP: " << thetaP << " is outside of the allowed domain" << std::endl;
		errorOutputBuffer->set_text("Unreachable coordinates");
	}

	else {
		std::cout << "x: " << coordinateX << ", y: " << coordinateY << " thetaM: " << result.first << " and thetaP: " << result.second << std::endl;
		thetaMOutputBuffer->set_text(std::to_string(thetaM));
		thetaPOutputBuffer->set_text(std::to_string(thetaP));
		thetaDOutputBuffer->set_text(std::to_string(2 * thetaP / 3));

		graphArea.updateAngles(thetaM, thetaP);
		errorOutputBuffer->set_text("");
	}
}

void GUIInverse::on_button_clicked() {
	bool validInput = getInputValueStartCoordinates();

	if (validInput) {
		calculateAngles(startCoordinateX, startCoordinateY);
	}

	if (getInputValueEndCoordinates() && getInputValueInterval()) {
		calculateAllAngles();
	}
}
	

void GUIInverse::calculateAllAngles() {


	// extra shit

	if (endCoordinateY < startCoordinateX) {
		float temp = startCoordinateY;
		startCoordinateY = endCoordinateY;
		endCoordinateY = temp;
	}

	if (endCoordinateX < startCoordinateY) {
		float temp = startCoordinateX;
		startCoordinateX = endCoordinateX;
		endCoordinateX = temp;
	}

	float length = sqrt(pow((endCoordinateX - startCoordinateX), 2) + pow((endCoordinateY - startCoordinateY), 2));
	float amount = length / interval; //amount of steps

	anglesArrayLength = amount;
	currentPositionAnglesArray = anglesArrayLength;

	if (anglesArray != NULL) {
		delete[] anglesArray;
	}
	anglesArray = new std::pair<float, float>[amount];


	float initX, initY;
	float endX, endY;

	bool swapX = false;

	

	if (startCoordinateX == endCoordinateX) {
		initX = startCoordinateY;
		endX = endCoordinateY;
		initY = startCoordinateX;
		endY = endCoordinateX;
		swapX = true;
	}
	else {
		initX = startCoordinateX;
		endX = endCoordinateX;
		initY = startCoordinateY;
		endY = endCoordinateY;
	}

	int i = 0;
	for (float x = initX; x <= endX; x += (endX-initX)/amount) {
		float y = linear(initX, endX, initY, endY, interval, x);


		if (swapX) {
			float temp = x;
			x = y;
			y = temp;
		}

		if (!isReachable(x, y)) {
			std::cerr << "Unreachable coordinates: " << x << ", " << y << std::endl; 
			break;
		}
		else {
			std::pair<float, float> result = mF.inverseRotate(x, y);
			if (isnan(result.first)) { 
				std::cerr << "Unreachable coordinates: " << x << ", " << y << std::endl;
			}
			else {
				//graphArea.updateAngles(result.first, result.second);
				std::cout << "x: " << x << ", y: " << y << " thetaM: " << result.first << " and thetaP: " << result.second << std::endl;
			}
			// even if its nan add it to the array
			anglesArray[i] = result;
			
		}

		if (swapX) {
			float temp = x;
			x = y;
			y = temp;
		}
		i++;
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
	// should be improved are now the outerpoint (without restriction)
	if (coordinateX >= -21.41 && coordinateX <= 88.31 && coordinateY >= -82.33 && coordinateY <= 76.48) {
		return true;
	}
	else {
		return false;
	}
}



bool GUIInverse::updateDrawing(Gtk::ScrollType st, double value) {
	std::cout << value << std::endl;
	return true;
}


void GUIInverse::nextInterval() {
	currentPositionAnglesArray++;
	if (currentPositionAnglesArray >= anglesArrayLength) {
		currentPositionAnglesArray = 0;
	}
	graphArea.updateAngles(anglesArray[currentPositionAnglesArray].first, anglesArray[currentPositionAnglesArray].second);
}

void GUIInverse::previousInterval() {

}