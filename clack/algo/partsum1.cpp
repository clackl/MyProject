#include "algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;

	INSERT_ELEMENT(coll, 1, 6);
	PRINT_ELEMENTS(coll);

	partial_sum(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	partial_sum(coll.begin(),coll.end(),ostream_iterator<int>())
}