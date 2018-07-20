#include "algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	INSERT_ELEMENT(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	cout << "sum: " << accumulate(coll.begin(), coll.end(), 0);

	cout << "product: " << accumulate(coll.begin(), coll.end(), 1, multiplies<int>()) << endl;

	cout << "product: " << accumulate(coll.begin(), coll.end(), 0, multiplies<int>()) << endl;


}