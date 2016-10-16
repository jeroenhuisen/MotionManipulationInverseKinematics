#include "MiddleFingerRotation.h"

MiddleFingerRotation::MiddleFingerRotation() {
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

	translation1.at(0, 3) = 44.6;
	translation2.at(0, 3) = 26.3;
	translation3.at(0, 3) = 17.4;
}

mat MiddleFingerRotation::rotate(float thetaM, float thetaP, float thetaD){
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
mat MiddleFingerRotation::rotate(float thetaM, float thetaP) {
	rotation1.at(0, 0) = cos(thetaM);
	rotation1.at(0, 1) = -1 * sin(thetaM);
	rotation1.at(1, 0) = sin(thetaM);
	rotation1.at(1, 1) = cos(thetaM);

	rotation2.at(0, 0) = cos(thetaP);
	rotation2.at(0, 1) = -1 * sin(thetaP);
	rotation2.at(1, 0) = sin(thetaP);
	rotation2.at(1, 1) = cos(thetaP);

	rotation3.at(0, 0) = cos(2 * thetaP / 3);
	rotation3.at(0, 1) = -1 * sin(2 * thetaP / 3);
	rotation3.at(1, 0) = sin(2 * thetaP / 3);
	rotation3.at(1, 1) = cos(2 * thetaP / 3);

	mat result = rotation1 * translation1;
	result *= rotation2;
	result *= translation2;
	result *= rotation3;
	result *= translation3;

	return result;
}