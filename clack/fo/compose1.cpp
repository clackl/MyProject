#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include "print.hpp"
#include "compose11.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	for (int i = 1; i <= 9; i++) {
		coll.push_back(i);
	}
	PRINT_ELEMENTS(coll);

	transform(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "),
		compose_f_gx(bind2nd(multiplies<int>(), 5),bind2nd(plus<int>(), 10)));
	cout << endl;
}



