#include <cstdlib>
#include "algostuff.hpp"
using namespace std;

bool absLess(int elem1, int elem2) {
	return abs(elem1) < abs(elem2);
}

int main()
{
	deque<int> coll;
	INSERT_ELEMENT(coll, 2, 8);
	INSERT_ELEMENT(coll, -3, 5);

	PRINT_ELEMENTS(coll);

	cout << "minimum: " << *min_element(coll.begin(), coll.end()) << endl;
	cout << "maximum: " << *max_element(coll.begin(), coll.end()) << endl;

	cout << "minimum of absoulute values: "
		<< *min_element(coll.begin(), coll.end(), absLess) << endl;
	cout << "maximum of absoulute values: "
		<< *max_element(coll.begin(), coll.end(), absLess) << endl;
}