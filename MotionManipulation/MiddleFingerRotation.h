#pragma once

#include <armadillo>
#include <math.h>

using namespace arma;

class MiddleFingerRotation{
private:
	mat rotation1, rotation2, rotation3;
	mat translation1, translation2, translation3;
public: 
	MiddleFingerRotation();
	mat rotate(float thetaM, float thetaP, float thetaD); 
	mat rotate(float thetaM, float thetaP);
	std::pair<float, float> rotateCoordinates(float thetaM, float thetaP);
	float rotateCoordinatesAndAngle(float thetaM, float thetaP);
};