//https://developer.gnome.org/gtkmm-tutorial/stable/sec-cairo-drawing-lines.html.en

#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

#include <gtkmm/drawingarea.h>

class GraphArea : public Gtk::DrawingArea
{
private:
	float thetaM, thetaP, thetaD;

	std::pair<float, float> startCoordinates, endCoordinates;
public:
	GraphArea();
	virtual ~GraphArea();
	void updateAngles(float thetaM, float thetaP);
	void updateLine(std::pair<float, float> startCoordinates, std::pair<float, float> endCoordinates);

protected:
	//Override default signal handler:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif // GTKMM_EXAMPLE_MYAREA_H