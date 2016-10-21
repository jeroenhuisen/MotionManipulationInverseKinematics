#pragma once

#include <armadillo>
#include <math.h>

using namespace arma;

#define PI 3.14159285358979323846264338327950

class Finger {
private:
	float ppLength, ipLength, dpLength;
	mat rotation1, rotation2, rotation3;
	mat translation1, translation2, translation3;

	float errorValue = 0.1;

	std::pair<float, float> calculateInitialGuess(float x, float y);
	//std::pair<float, float> calculateInverseRotation(float x, float y, float thetaM, float thetaP);
	std::pair<float, float> calculateInverseRotation(mat finalCoordinates, mat q);

	mat jacobian(float thetaM, float thetaP);
	mat inverseJacobian(float thetaM, float thetaP);
	mat inverseJacobian(mat q);

public:
	Finger(float ppLength, float ipLength, float dpLength);
	mat rotate(float thetaM, float thetaP, float thetaD);
	mat rotate(float thetaM, float thetaP);
	std::pair<float, float> rotateCoordinates(float thetaM, float thetaP, float thetaD);
	std::pair<float, float> rotateCoordinates(float thetaM, float thetaP);

	std::pair<float, float> rotateCoordinates(mat matrix);

	std::pair<float, float> inverseRotate(float x, float y);

};