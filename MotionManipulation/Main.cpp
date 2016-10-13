#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void main() {
	std::cout << "welcome noob" << std::endl;
	mat a = randu<mat>(4, 5);
	mat b = randu<mat>(4, 5);

	
	cout << a*b.t() << endl;

	system("pause");
}