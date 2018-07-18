#include "algostuff.hpp"
using namespace std;

//检验相等性
bool bothEvenOrOdd(int elem1,int elem2){
	return elem1 % 2 == elem2 % 2;
}

int main()
{
	vector<int> coll1;
	list<int> coll2;

	INSERT_ELEMENT(coll1, 1, 7);
	INSERT_ELEMENT(coll2, 3, 9);

	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");

	if (equal(coll1.begin(), coll1.end(), coll2.begin())) {
		cout << "coll1 == coll2" << endl;
	}
	else {
		cout << "coll1 != coll2" << endl;
	}

	if (equal(coll1.begin(), coll1.end(), coll2.begin(), bothEvenOrOdd)) {
		cout << "even and odd element correspond" << endl;
	}
	else {
		cout << "even and odd element do not correspond" << endl;
	}

}