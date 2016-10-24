#include "TestGraph.h"
#include <math.h>+

TestGraph::TestGraph(SFMLWidget& widget) : widget(widget) {

	//widget.renderWindow.draw(line);
}

void TestGraph::draw() {
	widget.renderWindow.clear(sf::Color::Black);
	sf::RectangleShape line(sf::Vector2f(150, 5));
	line.rotate(45);
	widget.renderWindow.draw(line);
	widget.display();
	//widget.renderWindow.display();
}


void TestGraph::drawTest(float thetaM, float thetaP) {
	sf::RectangleShape linePP(sf::Vector2f(44.6, 2));
	sf::RectangleShape lineIP(sf::Vector2f(26.3, 2));
	sf::RectangleShape lineDP(sf::Vector2f(17.4, 2));

	linePP.setPosition(sf::Vector2f(0, 0));
	sf::Transform transformPP;
	transformPP.rotate(thetaM, sf::Vector2f(0, 0));
	widget.renderWindow.draw(linePP, transformPP);

	sf::Vector2f position(cos(thetaM), sin(thetaM));
	lineIP.setPosition(position);
	sf::Transform transformIP;
	transformIP.rotate(thetaM, position);
	widget.renderWindow.draw(lineIP, transformIP);

	sf::Vector2f position2(cos(thetaM+thetaP), sin(thetaM+thetaP));
	lineDP.setPosition(position2);
	sf::Transform transformDP;
	transformDP.rotate(thetaM, position2);
	widget.renderWindow.draw(lineDP, transformDP);

	widget.renderWindow.display();
}