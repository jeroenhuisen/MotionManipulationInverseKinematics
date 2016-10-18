#pragma once

#include <armadillo>
#include <math.h>

using namespace arma;

class Finger {
private:
	float ppLength, ipLength, dpLength;
	mat rotation1, rotation2, rotation3;
	mat translation1, translation2, translation3;
public:
	Finger(float ppLength, float ipLength, float dpLength);
	mat rotate(float thetaM, float thetaP, float thetaD);
	mat rotate(float thetaM, float thetaP);
	std::pair<float, float> rotateCoordinates(float thetaM, float thetaP, float thetaD);
	std::pair<float, float> rotateCoordinates(float thetaM, float thetaP);
};