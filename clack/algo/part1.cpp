#include "algostuff.hpp"
using namespace std;

int main01()
{
	vector<int> coll1;
	vector<int> coll2;

	INSERT_ELEMENT(coll1, 1, 9);
	INSERT_ELEMENT(coll2, 1, 9);
	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");
	cout << endl;

	vector<int>::iterator pos1, pos2;
	pos1 = partition(coll1.begin(), coll1.end(), not1(bind2nd(modulus<int>(), 2)));

	pos2 = stable_partition(coll2.begin(), coll2.end(), not1(bind2nd(modulus<int>(), 2)));

	PRINT_ELEMENTS(coll1, "coll1: ");
	cout << "first odd element: " << *pos1 << endl;
	PRINT_ELEMENTS(coll2, "coll2: ");
	cout << "first odd element: " << *pos2 << endl;


}