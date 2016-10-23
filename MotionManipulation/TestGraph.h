#pragma once
#include <gtkmm.h>
#include "SFMLWidget.h"
#include "TestGraph.h"

class TestGraph 
{
public:
	// A simple circle shape that will be animated and drawn
	sf::CircleShape circle;

	// a reference to our SFMLWidget
	SFMLWidget& widget;

	TestGraph(SFMLWidget& widget);

	void draw();
};