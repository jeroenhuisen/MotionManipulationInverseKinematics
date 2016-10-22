#include "Finger.h"

Finger::Finger(float ppLength, float ipLength, float dpLength) {
	rotation1 = mat(4, 4);
	rotation1.zeros();
	rotation2 = mat(4, 4);
	rotation2.zeros();
	rotation3 = mat(4, 4);
	rotation3.zeros();

	for (int i = 2; i < 4; i++) {
		rotation1.at(i, i) = 1;
		rotation2.at(i, i) = 1;
		rotation3.at(i, i) = 1;
	}

	translation1 = mat(4, 4);
	translation1.zeros();
	translation2 = mat(4, 4);
	translation2.zeros();
	translation3 = mat(4, 4);
	translation3.zeros();

	for (int i = 0; i < 4; i++) {
		translation1.at(i, i) = 1;
		translation2.at(i, i) = 1;
		translation3.at(i, i) = 1;
	}

	translation1.at(0, 3) = ppLength;
	translation2.at(0, 3) = ipLength;
	translation3.at(0, 3) = dpLength;

	//Just store it to be sure
	this->ppLength = ppLength;
	this->ipLength = ipLength;
	this->dpLength = dpLength;
}

mat Finger::rotate(float thetaM, float thetaP, float thetaD) {
	rotation1.at(0, 0) = cos(thetaM);
	rotation1.at(0, 1) = -1 * sin(thetaM);
	rotation1.at(1, 0) = sin(thetaM);
	rotation1.at(1, 1) = cos(thetaM);

	rotation2.at(0, 0) = cos(thetaP);
	rotation2.at(0, 1) = -1 * sin(thetaP);
	rotation2.at(1, 0) = sin(thetaP);
	rotation2.at(1, 1) = cos(thetaP);

	rotation3.at(0, 0) = cos(thetaD);
	rotation3.at(0, 1) = -1 * sin(thetaD);
	rotation3.at(1, 0) = sin(thetaD);
	rotation3.at(1, 1) = cos(thetaD);

	mat result = rotation1 * translation1;
	result *= rotation2;
	result *= translation2;
	result *= rotation3;
	result *= translation3;

	return result;
}
mat Finger::rotate(float thetaM, float thetaP) {
	return 	rotate(thetaM, thetaP, 2 * thetaP / 3);
}


std::pair<float, float> Finger::rotateCoordinates(float thetaM, float thetaP, float thetaD) {
	mat result = rotate(thetaM, thetaP, thetaD);
	return std::make_pair(result.at(0, 3), result.at(1, 3));
}

std::pair<float, float> Finger::rotateCoordinates(float thetaM, float thetaP) {
	mat result = rotate(thetaM, thetaP);
	return std::make_pair(result.at(0, 3), result.at(1, 3));
}

std::pair<float, float> Finger::rotateCoordinates(mat matrix) {
	float thetaM = matrix.at(0, 0);
	float thetaP = matrix.at(1, 0);

	float x = ppLength*cos(thetaM) + ipLength * cos(thetaM + thetaP) + dpLength * cos(thetaM + 5 * thetaP / 3);
	float y = ppLength*sin(thetaM) + ipLength * sin(thetaM + thetaP) + dpLength * sin(thetaM + 5 * thetaP / 3);

	return std::make_pair(x, y);
}
/*
float Finger::rotateLastAngle(float thetaM, float thetaP) {
	mat result = rotate(thetaM, thetaP);
	std::pair<float, float> coordiantes = std::make_pair(result.at(0, 3), result.at(1, 3));
	float angle = acos(result.at(0, 0));
	std::cout << angle << std::endl;
	angle = angle * 180 / 3.14159265357989323846264338;
	std::cout << angle << std::endl;
	return angle;
}*/

std::pair<float, float> Finger::inverseRotate(float x, float y) {
	std::pair<float, float> initialGuess = calculateInitialGuess(x, y);
	mat q = mat(2, 1);
	q.at(0, 0) = initialGuess.first;
	q.at(1, 0) = initialGuess.second;

	mat finalCoordinates = mat(2, 1);
	finalCoordinates.at(0, 0) = x;
	finalCoordinates.at(1, 0) = y;
	return calculateInverseRotationNonRecursive(finalCoordinates, q);
}

// recursive
std::pair<float, float> Finger::calculateInverseRotation(mat finalCoordinates, mat q) {
	mat resultCoordinates = mat(2, 1);
	std::pair<float, float> result = rotateCoordinates(q);
	resultCoordinates.at(0, 0) = result.first;
	resultCoordinates.at(1, 0) = result.second;

	mat newQ = q + inverseJacobian(q) * (finalCoordinates - resultCoordinates);

	std::pair<float, float> newCoordinates = rotateCoordinates(newQ.at(0,0), newQ.at(1,0));
	std::cout << newCoordinates.first << ", " << newCoordinates.second << std::endl;
	std::cout << finalCoordinates.at(0, 0) << ", " << finalCoordinates(1, 0) << std::endl;
	if (newCoordinates.first  >= (finalCoordinates.at(0, 0) - errorValue) &&
		newCoordinates.first  <= (finalCoordinates.at(0, 0) + errorValue) &&
		newCoordinates.second >= (finalCoordinates.at(1, 0) - errorValue) &&
	    newCoordinates.second <= (finalCoordinates.at(1, 0) + errorValue) ){
		float newThetaM = newQ.at(0, 0);
		float newThetaP = newQ.at(1, 0);
		return std::make_pair(newThetaM, newThetaP);
	}
	else {
		return calculateInverseRotation(finalCoordinates, newQ);
	}
}

bool checkErrorValue(std::pair<float, float> newCoordinates, mat finalCoordinates, float errorValue) {
	return newCoordinates.first >= (finalCoordinates.at(0, 0) - errorValue) &&
		newCoordinates.first <= (finalCoordinates.at(0, 0) + errorValue) &&
		newCoordinates.second >= (finalCoordinates.at(1, 0) - errorValue) &&
		newCoordinates.second <= (finalCoordinates.at(1, 0) + errorValue);
}

// non recursive
std::pair<float, float> Finger::calculateInverseRotationNonRecursive(mat finalCoordinates, mat q) {
	mat resultCoordinates = mat(2, 1);
	std::pair<float, float> newCoordinates;
	mat newQ = q;
	int i;
	for (i=0;  !checkErrorValue(newCoordinates, finalCoordinates, errorValue); i++) {
		std::pair<float, float> result = rotateCoordinates(newQ);
		resultCoordinates.at(0, 0) = result.first;
		resultCoordinates.at(1, 0) = result.second;

		newQ = newQ + inverseJacobian(newQ) * (finalCoordinates - resultCoordinates);

		newCoordinates = rotateCoordinates(newQ.at(0, 0), newQ.at(1, 0));

		std::cout << newCoordinates.first << ", " << newCoordinates.second << std::endl;
		std::cout << finalCoordinates.at(0, 0) << ", " << finalCoordinates(1, 0) << std::endl;
	}
	std::cout << "rotations: " << i << std::endl;
	return std::make_pair(newQ.at(0, 0), newQ.at(1, 0));
}



std::pair<float, float> Finger::calculateInitialGuess(float x, float y) {
	return std::make_pair(0.0f, -PI / 3); //the middle of the possible angles
}

mat Finger::jacobian(float thetaM, float thetaP) {
	mat jacobian = mat(2, 2);
	jacobian.at(0, 0) = -ppLength * sin(thetaM) - ipLength * sin(thetaM + thetaP) - dpLength * sin(thetaM + 5 * thetaP / 3);
	jacobian.at(0, 1) = -ipLength * sin(thetaM + thetaP) - dpLength * 5/3 *sin(thetaM + 5 * thetaP / 3);
	jacobian.at(1, 0) = ppLength * cos(thetaM) + ipLength * cos(thetaM + thetaP) + dpLength * cos(thetaM + 5 * thetaP / 3);
	jacobian.at(1, 1) = ipLength * cos(thetaM + thetaP) + dpLength * 5/3 *cos(thetaM + 5 * thetaP / 3);
	return jacobian;
}

mat Finger::inverseJacobian(float thetaM, float thetaP) {
	mat inverseJacobian = mat(2, 2);
	/*float determinant = 1 / (ppLength * ipLength * sin(thetaP) + 1 / 3 * dpLength*(5 * ppLength*sin(5 * thetaP / 3) + 2 * ipLength*sin(2 * thetaP / 3)));

	inverseJacobian.at(0, 0) = (ipLength * cos(thetaM + thetaP) + dpLength * 5 / 3 * cos(thetaM + 5 * thetaP / 3)) *determinant;
	inverseJacobian.at(0, 1) = (-ipLength * sin(thetaM + thetaP) - dpLength * 5 / 3 * sin(thetaM + 5 * thetaP / 3)) * determinant * -1;
	inverseJacobian.at(1, 0) = (ppLength * cos(thetaM) + ipLength * cos(thetaM + thetaP) + dpLength * cos(thetaM + 5 * thetaP / 3)) *determinant * -1;
	inverseJacobian.at(1, 1) = (-ppLength * sin(thetaM) - ipLength * sin(thetaM + thetaP) - dpLength * sin(thetaM + 5 * thetaP / 3)) * determinant;*/

	float divide = 3 * ppLength * ipLength * sin(thetaP) + dpLength *(5.0f * ppLength*sin(5.0f * thetaP / 3.0f) + 2.0f * ipLength*sin(2.0f * thetaP / 3.0f));
	inverseJacobian.at(0, 0) = (3.0f * ipLength*cos(thetaM + thetaP) + 5 * dpLength * cos((3.0f * thetaM + 5.0f * thetaP) / 3.0f)) / divide;
	inverseJacobian.at(0, 1) = (-3.0f * ipLength*sin(thetaM + thetaP) - 5 * dpLength*sin((3.0f * thetaM + 5.0f * thetaP) / 3.0f)) / divide * -1.0f;
	inverseJacobian.at(1, 0) = (3.0f * (ipLength * cos(thetaM + thetaP) + dpLength * cos((3.0f * thetaM + 5.0f * thetaP) / 3.0f) + ppLength * cos(thetaM))) / divide * -1.0f;
	inverseJacobian.at(1, 1) = (3.0f * (-1.0f*ipLength * sin(thetaM + thetaP) - dpLength * sin((3.0f * thetaM + 5.0f * thetaP) / 3.0f) - ppLength * sin(thetaM))) / divide;

	return inverseJacobian;
}

mat Finger::inverseJacobian(mat q) {
	return inverseJacobian(q.at(0, 0), q.at(1, 0));
}
