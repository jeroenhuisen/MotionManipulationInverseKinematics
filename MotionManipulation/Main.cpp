#include <iostream>
#include <armadillo>
#include "MiddleFingerRotation.h"

using namespace std;
using namespace arma;

void roundMat(mat& a) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a.at(i, j) = round(a.at(i, j) * 100) / 100;
		}
	}
}
void main() {
	float pi = 3.14159265358979323846264338327950;
	std::cout << "welcome noob" << std::endl;
	mat a(4, 4);

	MiddleFingerRotation mfr;

	a = mfr.rotate(pi / 3, (-1 * pi) / 2), 2*(-1 * pi)/3;
	roundMat(a);
	cout << a << endl;
	a = mfr.rotate(pi/3, (-1*pi)/2);
	roundMat(a);
	cout << a;


	system("pause");
}

