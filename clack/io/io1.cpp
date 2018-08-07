#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int io1()
{
	double x, y;
	cout << "Multiplication of two floating point values" << endl;

	cout << "first operand: ";
	if (!(cin >> x)) {
		cerr << "error while reading the first floating value" << endl;
		return EXIT_FAILURE;
	}

	cout << "second operand: ";
	if (!(cin >> y)) {
		cerr << "error while reading the second floating value" << endl;
		return EXIT_FAILURE;
	}
	cout << x << " times " << y << " equals " << x * y << endl;

	return 0;
}