#include "algostuff.hpp"
using namespace std;

bool checkEven(int elem, bool even) {
	if (even) {
		return elem % 2 == 0;
	}
	else {
		return elem % 2 == 1;
	}
}

int main()
{
	vector<int> coll;
	INSERT_ELEMENT(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	bool checkEvenArgs[3] = { true,false,true };

	vector<int>::iterator pos;
	pos = search(coll.begin(), coll.end(),
		checkEvenArgs, checkEvenArgs + 3, checkEven);
}























int main01()
{
	deque<int> coll;
	list<int> subcoll;

	INSERT_ELEMENT(coll, 1, 7);
	INSERT_ELEMENT(coll, 1, 7);

	INSERT_ELEMENT(subcoll, 3, 6);

	PRINT_ELEMENTS(coll, "coll: ");
	PRINT_ELEMENTS(subcoll, "subcoll: ");

	deque<int>::iterator pos;
	pos = search(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());
	
	while (pos != coll.end()) {
		cout << "subcoll found starting with element "
			<< distance(coll.begin(), pos) + 1 << endl;
		++pos;
		pos = search(pos, coll.end(), subcoll.begin(), subcoll.end());
	}
}