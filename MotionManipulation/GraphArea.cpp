#include "GraphArea.h"
#include <cairomm/context.h>

GraphArea::GraphArea()
{
	thetaM = 0;
	thetaP = 0;
	thetaD = 0;
}

GraphArea::~GraphArea()
{
}

void GraphArea::updateAngles(float thetaM, float thetaP) {
	this->thetaM = thetaM;
	this->thetaP = thetaP;
	this->thetaD = 2 * thetaP / 3;

	auto win = get_window();
	if (win)
	{
		Gdk::Rectangle r(0, 0, get_allocation().get_width(),
			get_allocation().get_height());
		win->invalidate_rect(r, false);
	}
}

void GraphArea::updateLine(std::pair<float, float> startCoordinates, std::pair<float, float> endCoordinates) {
	this->startCoordinates = startCoordinates;
	this->endCoordinates = endCoordinates;

	auto win = get_window();
	if (win)
	{
		Gdk::Rectangle r(0, 0, get_allocation().get_width(),
			get_allocation().get_height());
		win->invalidate_rect(r, false);
	}
}

bool GraphArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();

	// coordinates for the center of the window
	int xc, yc;
	xc = width / 2;
	yc = height / 2;

	float l1 = 44.6*3;
	float l2 = 26.3*3;
	float l3 = 17.4*3;

	float initialX = xc/2;
	float initialY = yc;


	//test line
	/*cr->set_line_width(5.0);
	cr->set_source_rgb(0.0, 0.0, 0.0);
	//float test = initialY + startCoordinates.second * 3;
	cr->move_to(initialX, initialY);
	cr->line_to(initialX + 200, initialY);
	cr->stroke();*/

	// Draw line
	cr->set_line_width(5.0);
	cr->set_source_rgb(0.0, 0.0, 0.0);
	cr->move_to(initialX + startCoordinates.first*3, initialY - startCoordinates.second * 3);
	cr->line_to(initialX + endCoordinates.first*3, initialY - endCoordinates.second*3);
	cr->stroke();

	// Draw finger 
	cr->set_line_width(10.0);

	cr->set_source_rgb(0.8, 0.0, 0.0);
	cr->move_to(initialX, initialY);
	cr->line_to(initialX + l1*cos(thetaM), initialY + l1*-sin(thetaM));
	cr->stroke();

	cr->set_source_rgb(0.0, 0.8, 0.0);
	cr->move_to(initialX + l1*cos(thetaM), initialY + l1*-sin(thetaM));
	cr->line_to(initialX + l1*cos(thetaM) + l2*cos(thetaM+thetaP), initialY + l1*-sin(thetaM) + l2*-sin(thetaM+thetaP));
	cr->stroke();

	cr->set_source_rgb(0.0, 0.0, 0.8);
	cr->move_to(initialX + l1*cos(thetaM) + l2*cos(thetaM + thetaP), initialY + l1*-sin(thetaM) + l2*-sin(thetaM + thetaP));
	cr->line_to(initialX + l1*cos(thetaM) + l2*cos(thetaM + thetaP) + l3*cos(thetaM + 5* thetaP /3), initialY + l1*-sin(thetaM) + l2*-sin(thetaM + thetaP) + l3*-sin(thetaM + 5 * thetaP / 3));
	cr->stroke();
	return true;
}