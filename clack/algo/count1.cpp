#include <iostream>
#include "algostuff.hpp"
using namespace std;

bool isEven(int elem)
{
	return elem % 2 == 0;
}

int main()
{
	vector<int> coll;
	int num;

	INSERT_ELEMENT(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	num = count(coll.begin(), coll.end(), 4);
	cout << "number of elements equal to 4: " << num << endl;

	num = count_if(coll.begin(), coll.end(), isEven);
	cout << "number of elements with even value: " << num << endl;

	num = count_if(coll.begin(), coll.end(), bind1st(greater<int>(), 4));
	cout << "number of element greater than 4: " << num << endl;
}