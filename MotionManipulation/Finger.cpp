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