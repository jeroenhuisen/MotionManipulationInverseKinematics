#include "TestGraph.h"

TestGraph::TestGraph(SFMLWidget& widget) : widget(widget) {


	//widget.renderWindow.draw(line);
}

void TestGraph::draw() {
	sf::RectangleShape line(sf::Vector2f(150, 5));
	line.rotate(45);
	widget.renderWindow.draw(line);
}
