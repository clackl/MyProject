#include "algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;

	INSERT_ELEMENT(coll, 1, 6);
	PRINT_ELEMENTS(coll);

	cout << "inner product: " << inner_product(coll.begin(), coll.end(), coll.begin(), 0) << endl;

	cout << "inner reverse product: " << inner_product(coll.begin(), coll.end(), coll.rbegin(), 0) << endl;

	cout << "product of sum: " 
		<< inner_product(coll.begin(), coll.end(), coll.begin(), 1,multiplies<int>(),plus<int>()) << endl;
}
